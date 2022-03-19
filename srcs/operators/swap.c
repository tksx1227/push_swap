/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:55:34 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 11:32:07 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_one_stack(t_stack *stack)
{
	int	tmp;

	if (2 <= stack->size)
	{
		tmp = stack->elems[0];
		stack->elems[0] = stack->elems[1];
		stack->elems[1] = tmp;
	}
}

void	swap_two_stacks(t_stack *stack1, t_stack *stack2)
{
	swap_one_stack(stack1);
	swap_one_stack(stack2);
}
