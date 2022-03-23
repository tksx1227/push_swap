/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elems.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:59:26 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/23 09:04:04 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_by_pattern(t_stack *stack, int pattern_no);

void	sort_three_elems(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->elems[0];
	second = stack->elems[1];
	third = stack->elems[2];
	if (second < first && second < third && first < third)
		sort_by_pattern(stack, 1);
	else if (second < first && second < third && third < first)
		sort_by_pattern(stack, 2);
	else if (first < second && third < second && third < first)
		sort_by_pattern(stack, 3);
	else if (first < second && third < second && first < third)
		sort_by_pattern(stack, 4);
	else if (second < first && third < second)
		sort_by_pattern(stack, 5);
}

static void	sort_by_pattern(t_stack *stack, int pattern_no)
{
	if (pattern_no == 1)
		swap_one_stack_with_print(stack, true);
	else if (pattern_no == 2)
		rotate_one_stack_with_print(stack, true);
	else if (pattern_no == 3)
		rrotate_one_stack_with_print(stack, true);
	else if (pattern_no == 4)
	{
		swap_one_stack_with_print(stack, true);
		rotate_one_stack_with_print(stack, true);
	}
	else if (pattern_no == 5)
	{
		swap_one_stack_with_print(stack, true);
		rrotate_one_stack_with_print(stack, true);
	}
}
