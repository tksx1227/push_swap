/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:20:28 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/13 14:54:43 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_base(t_stack *from, t_stack *to);

void	push_a(t_container *container)
{
	t_stack	*to_stack;
	t_stack	*from_stack;

	to_stack = container->stack1;
	from_stack = container->stack2;
	push_base(from_stack, to_stack);
}

void	push_b(t_container *container)
{
	t_stack	*to_stack;
	t_stack	*from_stack;

	to_stack = container->stack2;
	from_stack = container->stack1;
	push_base(from_stack, to_stack);
}

static void	push_base(t_stack *from_stack, t_stack *to_stack)
{
	t_list	*target;

	if (0 < from_stack->size)
	{
		target = from_stack->elements;
		from_stack->elements = from_stack->elements->next;
		if (from_stack->elements != NULL)
			from_stack->elements->prev = NULL;
		target->prev = NULL;
		target->next = to_stack->elements;
		if (to_stack->elements != NULL)
			to_stack->elements->prev = target;
		to_stack->elements = target;
		to_stack->size++;
		from_stack->size--;
	}
}
