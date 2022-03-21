/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:53:50 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/21 19:19:35 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_dprintf.h"

typedef struct s_stack
{
	int		*elems;
	char	*name;
	size_t	size;
}	t_stack;

/* Utils */
bool		is_valid_args(int size, char **args);
bool		is_sorted_stack(t_stack *stack);
t_stack		*get_new_stack(int size, char **arr, char *name);
void		free_stack(t_stack **stack);
void		show_stack(t_stack *stack, char *name);
void		show_operators(t_list *operators);
t_status	convert_simple_arr(t_stack *stack);
int			get_mid_from_sequence(int *arr, size_t size);
int			ft_strcmp(const char *s1, const char *s2);
void		print_operator(char *from_stack_name, char *to_stack_name, \
		char *operator_name);
void		sort_recursion_for_stack_a(t_stack *from_stack, t_stack *to_stack, \
		size_t origin_chunk_size);

/* Operators */
void		swap_one_stack(t_stack *stack);
void		swap_two_stacks(t_stack *stack1, t_stack *stack2);
void		push_stack(t_stack *from_stack, t_stack *to_stack);
void		rotate_one_stack(t_stack *stack);
void		rotate_two_stacks(t_stack *stack1, t_stack *stack2);
void		rrotate_one_stack(t_stack *stack);
void		rrotate_two_stacks(t_stack *stack1, t_stack *stack2);

#endif
