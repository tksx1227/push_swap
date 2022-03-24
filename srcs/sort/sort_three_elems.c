/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elems.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:59:26 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/23 23:44:35 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_by_pattern(t_stack *stack, int pattern_no, t_list **operators);

void	sort_three_elems(t_stack *stack, t_list **operators)
{
	int	first;
	int	second;
	int	third;

	first = stack->elems[0];
	second = stack->elems[1];
	third = stack->elems[2];
	if (second < first && second < third && first < third)
		sort_by_pattern(stack, 1, operators);
	else if (second < first && second < third && third < first)
		sort_by_pattern(stack, 2, operators);
	else if (first < second && third < second && third < first)
		sort_by_pattern(stack, 3, operators);
	else if (first < second && third < second && first < third)
		sort_by_pattern(stack, 4, operators);
	else if (second < first && third < second)
		sort_by_pattern(stack, 5, operators);
}

static void	sort_by_pattern(t_stack *stack, int pattern_no, t_list **operators)
{
	if (pattern_no == 1)
		swap_and_set_operator(stack, operators);
	else if (pattern_no == 2)
		rotate_and_set_operator(stack, operators);
	else if (pattern_no == 3)
		rrotate_and_set_operator(stack, operators);
	else if (pattern_no == 4)
	{
		swap_and_set_operator(stack, operators);
		rotate_and_set_operator(stack, operators);
	}
	else if (pattern_no == 5)
	{
		swap_and_set_operator(stack, operators);
		rrotate_and_set_operator(stack, operators);
	}
}
