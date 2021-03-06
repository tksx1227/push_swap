/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:54:52 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/23 23:54:36 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_val(\
		t_stack *from_stack, t_stack *to_stack, t_list **operators);

void	sort_four_elems(t_stack *stack1, t_stack *stack2, t_list **operators)
{
	move_min_val(stack1, stack2, operators);
	sort_three_elems(stack1, operators);
	push_and_set_operator(stack2, stack1, operators);
}

static void	move_min_val(\
		t_stack *from_stack, t_stack *to_stack, t_list **operators)
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
			push_and_set_operator(from_stack, to_stack, operators);
			break ;
		}
		else
			rotate_and_set_operator(from_stack, operators);
	}
}
