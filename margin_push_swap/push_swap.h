#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h> /* for malloc */
# include <unistd.h> /* for write */
#include <stdio.h>

typedef struct s_push_swap
{
	int					number;
	int					rank;
	struct s_push_swap	*next;
	struct s_push_swap	*previous;
	
}	t_push_swap;

/*		Main.c			*/

int			main(int argc, char **argv);
t_push_swap	*ft_ps_stack_creation(int argc, char **argv);
void		ft_ps_free_and_exit(t_push_swap **stack_a, t_push_swap **stack_b);
int			ft_ps_atoi(t_push_swap **stack_a, char *str);
void		ft_ps_arguments_check(t_push_swap **stack_a);

/*		Algorithm.c		*/

void    	ft_algorithm(t_push_swap **stack_a, t_push_swap **stack_b);
void    	ft_algorithm_part_2(t_push_swap **stack_a, t_push_swap **stack_b);

/*		Lst_utils.c		*/

int			ft_ps_lst_size(t_push_swap **stack);
int			ft_ps_lst_is_sorted(t_push_swap *lst);
t_push_swap *ft_ps_lst_last(t_push_swap *lst);

/*		Push_ans_swap_functs.c	*/

void		ft_push_from_a_to_b(t_push_swap **stack_a, t_push_swap **stack_b);
void		ft_push_from_b_to_a(t_push_swap **stack_b, t_push_swap **stack_a);
void		ft_swap_a(t_push_swap **stack_a);

/*		Rotate_functs.c	*/

void		ft_rotate_a(t_push_swap **stack_a);
void		ft_rotate_b(t_push_swap **stack_b);
void		ft_reverse_rotate_a(t_push_swap **stack_a);
void		ft_reverse_rotate_b(t_push_swap **stack_b);

/*		Utils_algorithm.c	*/

void		ft_ps_ranking(t_push_swap **stack_a);
int			ft_find_direction_max(t_push_swap **stack_b);
int			ft_find_new_max(t_push_swap *lst);

#endif