/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:55:34 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 20:09:30 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_one_stack_with_print(t_stack *stack, bool need_print)
{
	int	tmp;

	if (2 <= stack->size)
	{
		tmp = stack->elems[0];
		stack->elems[0] = stack->elems[1];
		stack->elems[1] = tmp;
		if (need_print)
			print_operator(stack->name, "swap");
	}
}

void	swap_two_stacks_with_print(\
		t_stack *stack1, t_stack *stack2, bool need_print)
{
	swap_one_stack_with_print(stack1, need_print);
	swap_one_stack_with_print(stack2, need_print);
}
