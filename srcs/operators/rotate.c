/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:34:58 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/11 15:32:32 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_base(t_stack *stack);

void	rotate_a(t_container *container)
{
	rotate_base(container->stack1);
}

void	rotate_b(t_container *container)
{
	rotate_base(container->stack2);
}

void	rotate_ab(t_container *container)
{
	rotate_a(container);
	rotate_b(container);
}

static void	rotate_base(t_stack *stack)
{
	t_list	*head;

	if (2 <= stack->size)
	{
		head = stack->elements;
		stack->elements = stack->elements->next;
		stack->elements->prev = NULL;
		head->prev = NULL;
		head->next = NULL;
		ft_lstadd_back(&(stack->elements), head);
	}
}
