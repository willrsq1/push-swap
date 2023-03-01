#include "push_swap.h"

void	ft_ps_ranking(t_push_swap **stack_a)
{
	int	min;
	int	rank;
	int	size;
	t_push_swap	*lst;

	rank = 1;
	size = ft_ps_lst_size(stack_a);
	lst = *stack_a;
	while (rank < size + 1 && lst)
	{
		lst = *stack_a;
		min = 2147483647;
		while (lst)
		{
			if (lst->number < min && lst->rank < 0)
				min = lst->number;
			lst = lst->next;
		}
		lst = *stack_a;
		while (lst->number != min)
			lst = lst->next;
		lst->rank = rank;
		rank = rank + 1;
	}
}

int	ft_find_direction_max(t_push_swap **stack_b)
{
	t_push_swap	*lst;
	t_push_swap	*end;
	int		max;

	lst = *stack_b;
	end = ft_ps_lst_last(*stack_b);
	max = -2147483648;
	while (lst)
	{
		if (lst->rank >= max)
			max = lst->rank;
		lst = lst->next;
	}
	lst = *stack_b;
	while (lst && end)
	{
		if (lst->rank == max)
			return (1);
		if (end->rank == max)
			return (-1);
		lst = lst->next;
		end = end->previous;
	}
	return (0);
}

int	ft_find_new_max(t_push_swap *lst)
{
	int	max;

	max = -1;
	while (lst)
	{
		if (lst->rank >= max)
			max = lst->rank;
		lst = lst->next;
	}
	return (max);
}
