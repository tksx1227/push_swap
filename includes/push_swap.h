/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:53:50 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/24 09:32:36 by ttomori          ###   ########.fr       */
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
bool	is_valid_args(int size, char **args);
bool	is_sorted_stack(t_stack *stack);
t_stack	*get_new_stack(int size, char **arr, t_stack_name name);
void	free_two_stacks(t_stack **stack1, t_stack **stack2);
void	show_stack(t_stack *stack);
void	convert_to_sequence(t_stack *stack);
int		get_mid_from_sequence(int *arr, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
void	print_operators(t_list **operators);
void	move_lt_mid(t_stack *from_stack, t_stack *to_stack, \
		size_t chunk_size, t_list **operators);
void	move_gt_mid(t_stack *from_stack, t_stack *to_stack, \
		size_t chunk_size, t_list **operators);

/* Sort functions */
void	sort_three_elems(t_stack *stack, t_list **operators);
void	sort_four_elems(t_stack *stack1, t_stack *stack2, \
		t_list **operators);
void	sort_five_elems(t_stack *stack1, t_stack *stack2, \
		t_list **operators);
void	sort_le_five(t_stack *stack1, t_stack *stack2, t_list **operators);
void	sort_gt_five(t_stack *stack1, t_stack *stack2, t_list **operators);
void	sort_recursive_for_stack_a(t_stack *from_stack, t_stack *to_stack, \
		size_t origin_size, t_list **operators);
void	sort_recursive_for_stack_b(t_stack *from_stack, t_stack *to_stack, \
		size_t origin_chunk_size, t_list **operators);

/* Operators */
void	swap_and_set_operator(t_stack *stack, t_list **operators);
void	swap_double_and_set_operator(t_stack *stack1, t_stack *stack2, \
		t_list **operators);
void	push_and_set_operator(t_stack *from_stack, t_stack *to_stack, \
		t_list **operators);
void	rotate_and_set_operator(t_stack *stack, t_list **operators);
void	rotate_double_and_set_operator(t_stack *stack1, t_stack *stack2, \
		t_list **operators);
void	rrotate_and_set_operator(t_stack *stack, t_list **operators);
void	rrotate_double_and_set_operator(t_stack *stack1, t_stack *stack2, \
		t_list **operators);

#endif
