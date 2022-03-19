/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:34:58 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 12:04:35 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_one_stack(t_stack *stack)
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
	}
}

void	rotate_two_stacks(t_stack *stack1, t_stack *stack2)
{
	rotate_one_stack(stack1);
	rotate_one_stack(stack2);
}
