/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elems.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:59:26 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 20:05:22 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case1_3_5(t_stack *stack, int num);
static void	case2_4(t_stack *stack, int num);

void	sort_three_elems(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->elems[0];
	second = stack->elems[1];
	third = stack->elems[2];
	if (second < first && second < third && first < third)
		case1_3_5(stack, 1);
	else if (third < second && second < first)
		case2_4(stack, 2);
	else if (second < first && second < third && third < first)
		case1_3_5(stack, 3);
	else if (first < second && third < second && first < third)
		case2_4(stack, 4);
	else if (first < second && third < second && third < first)
		case1_3_5(stack, 5);
}

static void	case1_3_5(t_stack *stack, int num)
{
	if (num == 1)
		swap_one_stack_with_print(stack, true);
	else if (num == 3)
		rotate_one_stack_with_print(stack, true);
	else if (num == 5)
		rrotate_one_stack_with_print(stack, true);
}

static void	case2_4(t_stack *stack, int num)
{
	if (num == 2)
	{
		swap_one_stack_with_print(stack, true);
		rrotate_one_stack_with_print(stack, true);
	}
	else if (num == 4)
	{
		swap_one_stack_with_print(stack, true);
		rotate_one_stack_with_print(stack, true);
	}
}
