/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:53:50 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/11 14:54:24 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_dprintf.h"

typedef enum e_operator
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_operator;

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

/* Operators */
// sa, sb, ss
void	swap_a(t_container *container);
void	swap_b(t_container *container);
void	swap_ab(t_container *container);
// pa, pb
void	push_a(t_container *container);
void	push_b(t_container *container);

#endif
