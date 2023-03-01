#include "push_swap.h"

int main(int argc, char **argv)
{
	t_push_swap *stack_a;
	t_push_swap *stack_b;

	if (argc != 1)
	{
		stack_a = ft_ps_stack_creation(argc, argv);
		stack_b = NULL;
		ft_ps_arguments_check(&stack_a);
		ft_algorithm(&stack_a, &stack_b);
		ft_ps_free_and_exit(&stack_a, &stack_b);
	}
	return (0);
}

t_push_swap *ft_ps_stack_creation(int argc, char **argv)
{
	t_push_swap *first_lst;
	t_push_swap *lst;
	t_push_swap *temp;
	int i;

	first_lst = malloc(sizeof(t_push_swap));
	if (!first_lst)
		ft_ps_free_and_exit(NULL, NULL);
	first_lst->number = ft_ps_atoi(NULL, argv[1]);
	first_lst->rank = -1;
	first_lst->previous = NULL;
	temp = first_lst;
	i = 1;
	while (++i < argc)
	{
		lst = malloc(sizeof(t_push_swap));
		lst->number = ft_ps_atoi(&first_lst, argv[i]);
		lst->rank = -1;
		lst->previous = temp;
		temp->next = lst;
		temp = lst;
	}
	return (first_lst);
}

void ft_ps_free_and_exit(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap *lst;
	t_push_swap *temp;

	exit(0);
	lst = *stack_a;
	if (lst)
	{
		while (lst)
		{
			temp = lst;
			lst = lst->next;
			free(temp);
		}
	}
	lst = *stack_b;
	if (lst)
	{
		while (lst)
		{
			temp = lst;
			lst = lst->next;
			free(temp);
		}
	}
	exit(0);
}

int ft_ps_atoi(t_push_swap **stack_a, char *str)
{
	unsigned long long result;
	int sign;
	int i;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - 48);
	if (i == 0 || (i == 1 && (str[0] == '-' || str[0] == '+')))
		ft_ps_free_and_exit(stack_a, NULL);
	if ((result >= 2147483648 && sign == 1) || str[i] != '\0')
		ft_ps_free_and_exit(stack_a, NULL);
	if (result > 2147483648 && sign == -1)
		ft_ps_free_and_exit(stack_a, NULL);
	return (result * sign);
}

void ft_ps_arguments_check(t_push_swap **stack_a)
{
	t_push_swap *temp;
	t_push_swap *dpl;

	temp = *stack_a;
	while (temp)
	{
		dpl = temp->next;
		while (dpl)
		{
			if (dpl->number == temp->number)
				ft_ps_free_and_exit(stack_a, NULL);
			dpl = dpl->next;
		}
		temp = temp->next;
	}
	if (ft_ps_lst_is_sorted(*stack_a) == 1)
		ft_ps_free_and_exit(stack_a, NULL);
}