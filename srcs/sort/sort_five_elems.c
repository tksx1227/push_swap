/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:56:24 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 18:35:22 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_val(t_stack *stack);
static int	get_max_val(t_stack *stack);
static void	move_min_and_max_val(t_stack *from_stack, t_stack *to_stack);

void	sort_five_elems(t_stack *stack1, t_stack *stack2)
{
	move_min_and_max_val(stack1, stack2);
	if (stack2->elems[1] < stack2->elems[0])
	{
		swap_one_stack(stack2);
		print_operator(stack2->name, "swap");
	}
	sort_three_elems(stack1);
	push_stack(stack2, stack1);
	push_stack(stack2, stack1);
	rotate_one_stack(stack1);
	print_operator(stack2->name, "push");
	print_operator(stack2->name, "push");
	print_operator(stack1->name, "rotate");
}

static void	move_min_and_max_val(t_stack *from_stack, t_stack *to_stack)
{
	int	i;
	int	min_val;
	int	max_val;

	i = 0;
	min_val = get_min_val(from_stack);
	max_val = get_max_val(from_stack);
	while (i < 2)
	{
		if (min_val == *from_stack->elems || max_val == *from_stack->elems)
		{
			push_stack(from_stack, to_stack);
			print_operator(from_stack->name, "push");
			i++;
		}
		else
		{
			rotate_one_stack(from_stack);
			print_operator(from_stack->name, "rotate");
		}
	}
}

static int	get_min_val(t_stack *stack)
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
	return (min_val);
}

static int	get_max_val(t_stack *stack)
{
	size_t	i;
	int		max_val;

	i = 0;
	max_val = INT_MIN;
	while (i < from_stack->size)
	{
		if (max_val < from_stack->elems[i])
			max_val = from_stack->elems[i];
		i++;
	}
	return (max_val);
}
