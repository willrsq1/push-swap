#include "push_swap.h"

void		ft_rotate_a(t_push_swap **stack_a)
{
	t_push_swap	*first;
	t_push_swap	*last;
	t_push_swap	*second;

	first = *stack_a;
	last = ft_ps_lst_last(*stack_a);
	second = first->next;
	*stack_a = second;
	second->previous = NULL;
	first->previous = last;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void		ft_rotate_b(t_push_swap **stack_b)
{
	t_push_swap	*first;
	t_push_swap	*last;
	t_push_swap	*second;

	first = *stack_b;
	last = ft_ps_lst_last(*stack_b);
	if (!first || first->next == NULL)
		return ;
	second = first->next;
	*stack_b = second;
	second->previous = NULL;
	first->previous = last;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

void		ft_reverse_rotate_a(t_push_swap **stack_a)
{
	t_push_swap	*first;
	t_push_swap	*last;
	t_push_swap	*second_to_last;

	first = *stack_a;
	last = ft_ps_lst_last(*stack_a);
	second_to_last = last->previous;
	*stack_a = last;
	first->previous = last;
	last->next = first;
	last->previous = NULL;
	second_to_last->next = NULL;
	write(1, "rra\n", 4);
}

void		ft_reverse_rotate_b(t_push_swap **stack_b)
{
	t_push_swap	*first;
	t_push_swap	*last;
	t_push_swap	*second_to_last;

	first = *stack_b;
	last = ft_ps_lst_last(*stack_b);
	second_to_last = last->previous;
	*stack_b = last;
	first->previous = last;
	last->next = first;
	last->previous = NULL;
	second_to_last->next = NULL;
	write(1, "rrb\n", 4);
}