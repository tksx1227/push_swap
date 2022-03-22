/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:34:58 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 20:09:17 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_one_stack_with_print(t_stack *stack, bool need_print)
{
	size_t	i;
	int		last_num;

	if (2 <= stack->size)
	{
		i = stack->size - 1;
		last_num = stack->elems[i];
		while (0 < i)
		{
			stack->elems[i] = stack->elems[i - 1];
			i--;
		}
		stack->elems[i] = last_num;
		if (need_print)
			print_operator(stack->name, "rrotate");
	}
}

void	rrotate_two_stacks_with_print(\
		t_stack *stack1, t_stack *stack2, bool need_print)
{
	rrotate_one_stack_with_print(stack1, need_print);
	rrotate_one_stack_with_print(stack2, need_print);
}
