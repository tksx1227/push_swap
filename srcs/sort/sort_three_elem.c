/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:59:26 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 12:43:02 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case1_3_5(t_stack *stack, t_stack *stack2, int num);
static void	case2_4(t_stack *stack1, t_stack *stack2, int num);

void	sort_three_elem(t_stack *stack1, t_stack *stack2)
{
	int		first;
	int		second;
	int		third;

	first = stack1->elems[0];
	second = stack1->elems[1];
	third = stack1->elems[2];
	if (second < first && second < third && first < third)
		case1_3_5(stack1, stack2, 1);
	else if (third < second && second < first)
		case2_4(stack1, stack2, 2);
	else if (second < first && second < third && third < first)
		case1_3_5(stack1, stack2, 3);
	else if (first < second && third < second && first < third)
		case2_4(stack1, stack2, 4);
	else if (first < second && third < second && third < first)
		case1_3_5(stack1, stack2, 5);
}

static void	case1_3_5(t_stack *stack1, t_stack *stack2, int num)
{
	(void)stack2;
	if (num == 1)
	{
		swap_one_stack(stack1);
		print_operator(stack1->name, stack2->name, "swap");
	}
	else if (num == 3)
	{
		rotate_one_stack(stack1);
		print_operator(stack1->name, stack2->name, "rotate");
	}
	else if (num == 5)
	{
		rrotate_one_stack(stack1);
		print_operator(stack1->name, stack2->name, "rrotate");
	}
}

static void	case2_4(t_stack *stack1, t_stack *stack2, int num)
{
	(void)stack2;
	if (num == 2)
	{
		swap_one_stack(stack1);
		rrotate_one_stack(stack1);
		print_operator(stack1->name, stack2->name, "swap");
		print_operator(stack1->name, stack2->name, "rrotate");
	}
	else if (num == 4)
	{
		swap_one_stack(stack1);
		rotate_one_stack(stack1);
		print_operator(stack1->name, stack2->name, "swap");
		print_operator(stack1->name, stack2->name, "rotate");
	}
}
