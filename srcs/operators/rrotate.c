/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:34:58 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 12:04:45 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_one_stack(t_stack *stack)
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
	}
}

void	rrotate_two_stacks(t_stack *stack1, t_stack *stack2)
{
	rrotate_one_stack(stack1);
	rrotate_one_stack(stack2);
}
