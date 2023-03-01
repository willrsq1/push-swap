#include "push_swap.h"

int	ft_ps_lst_size(t_push_swap **stack)
{
	int	i;
	t_push_swap	*lst;

	i = 0;
	lst = *stack;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_ps_lst_is_sorted(t_push_swap *lst)
{
	int		temp;
	t_push_swap	*being_checked;

	while (lst)
	{
		being_checked = lst;
		temp = lst->number;
		while (lst->next)
		{
			lst = lst->next;
			if (lst->number < temp)
				return (0);
		}
		lst = being_checked->next;
	}
	return (1);
}

t_push_swap *ft_ps_lst_last(t_push_swap *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}