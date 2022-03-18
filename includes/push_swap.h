/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:53:50 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/18 10:14:34 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_dprintf.h"

typedef struct s_stack
{
	size_t	size;
	t_list	*elements;
}	t_stack;

typedef struct s_container
{
	t_stack	*stack1;
	t_stack	*stack2;
}	t_container;

/* Utils */
bool		is_valid_args(int size, char **args);
bool		is_sorted_stack(t_stack *stack);
t_container	*get_new_container(int size, char **arr);
void		free_container(t_container *container);
void		show_two_stacks(t_container *container);

/* Operators */
// sa, sb, ss
void		swap_a(t_container *container);
void		swap_b(t_container *container);
void		swap_ab(t_container *container);
// pa, pb
void		push_a(t_container *container);
void		push_b(t_container *container);
// ra, rb, rr
void		rotate_a(t_container *container);
void		rotate_b(t_container *container);
void		rotate_ab(t_container *container);
// rra, rrb, rrr
void		rrotate_a(t_container *container);
void		rrotate_b(t_container *container);
void		rrotate_ab(t_container *container);

#endif
