/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:53:50 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 13:16:30 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_dprintf.h"

typedef struct s_stack
{
	size_t	size;
	int		*elems;
}	t_stack;

/* Utils */
bool		is_valid_args(int size, char **args);
bool		is_sorted_stack(t_stack *stack);
t_stack		*get_new_stack(int size, char **arr);
void		free_stack(t_stack **stack);
void		show_stack(t_stack *stack, char *name);
void		show_operators(t_list *operators);

/* Operators */
void		swap_one_stack(t_stack *stack);
void		swap_two_stacks(t_stack *stack1, t_stack *stack2);
void		push_stack(t_stack *from_stack, t_stack *to_stack);
void		rotate_one_stack(t_stack *stack);
void		rotate_two_stacks(t_stack *stack1, t_stack *stack2);
void		rrotate_one_stack(t_stack *stack);
void		rrotate_two_stacks(t_stack *stack1, t_stack *stack2);

#endif
