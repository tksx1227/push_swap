/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:07:12 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 12:11:12 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted_stack(t_stack *stack)
{
	size_t	i;

	if (1 < stack->size)
	{
		i = 0;
		while (i < stack->size - 1)
		{
			if (stack->elems[i + 1] < stack->elems[i])
				return (false);
			i++;
		}
	}
	return (true);
}
