/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:34:58 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 20:09:07 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_one_stack_with_print(t_stack *stack, bool need_print)
{
	size_t	i;
	int		first_num;

	if (2 <= stack->size)
	{
		i = 0;
		first_num = stack->elems[i];
		while (i < stack->size - 1)
		{
			stack->elems[i] = stack->elems[i + 1];
			i++;
		}
		stack->elems[i] = first_num;
		if (need_print)
			print_operator(stack->name, "rotate");
	}
}

void	rotate_two_stacks_with_print(\
		t_stack *stack1, t_stack *stack2, bool need_print)
{
	rotate_one_stack_with_print(stack1, need_print);
	rotate_one_stack_with_print(stack2, need_print);
}
