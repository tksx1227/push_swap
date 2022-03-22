/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:53:50 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 20:03:25 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_dprintf.h"

typedef enum e_stack_name
{
	STACK_A,
	STACK_B,
}	t_stack_name;

typedef struct s_stack
{
	int				*elems;
	size_t			size;
	t_stack_name	name;
}	t_stack;

/* Utils */
bool		is_valid_args(int size, char **args);
bool		is_sorted_stack(t_stack *stack);
t_stack		*get_new_stack(int size, char **arr, t_stack_name name);
void		free_two_stacks(t_stack **stack1, t_stack **stack2);
void		show_stack(t_stack *stack);
t_status	convert_to_sequence(t_stack *stack);
int			get_mid_from_sequence(int *arr, size_t size);
int			ft_strcmp(const char *s1, const char *s2);
void		print_operator(t_stack_name stack_name, char *operator_name);

/* Sort functions */
void		sort_three_elems(t_stack *stack);
void		sort_four_elems(t_stack *stack1, t_stack *stack2);
void		sort_five_elems(t_stack *stack1, t_stack *stack2);
void		sort_le_five(t_stack *stack1, t_stack *stack2);
void		sort_gt_five(t_stack *stack1, t_stack *stack2);

/* Operators */
void		swap_one_stack_with_print(\
		t_stack *stack, bool need_print);
void		swap_two_stacks_with_print(\
		t_stack *stack1, t_stack *stack2, bool need_print);
void		push_stack_with_print(\
		t_stack *from_stack, t_stack *to_stack, bool need_print);
void		rotate_one_stack_with_print(\
		t_stack *stack, bool need_print);
void		rotate_two_stacks_with_print(\
		t_stack *stack1, t_stack *stack2, bool need_print);
void		rrotate_one_stack_with_print(\
		t_stack *stack, bool need_print);
void		rrotate_two_stacks_with_print(\
		t_stack *stack1, t_stack *stack2, bool need_print);

#endif
