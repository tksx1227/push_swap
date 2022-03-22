/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:54:52 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 17:58:49 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_val(t_stack *from_stack, t_stack *to_stack);

void	sort_four_elems(t_stack *stack1, t_stack *stack2)
{
	move_min_val(stack1, stack2);
	sort_three_elems(stack1);
	push_stack(stack2, stack1);
	print_operator(stack2->name, "push");
}

static void	move_min_val(t_stack *from_stack, t_stack *to_stack)
{
	size_t	i;
	int		min_val;

	i = 0;
	min_val = INT_MAX;
	while (i < from_stack->size)
	{
		if (from_stack->elems[i] < min_val)
			min_val = from_stack->elems[i];
		i++;
	}
	while (1)
	{
		if (min_val == *from_stack->elems)
		{
			push_stack(from_stack, to_stack);
			print_operator(from_stack->name, "push");
			break ;
		}
		else
		{
			rotate_one_stack(from_stack);
			print_operator(from_stack->name, "rotate");
		}
	}
}
