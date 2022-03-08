/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:55:34 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/08 23:59:28 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_base(t_list *list1, t_list *list2);

void	swap_a(t_container *container)
{
	t_stack	*stack;

	stack = container->stack1;
	if (2 <= stack->size)
	{
		swap_base(stack->elements, stack->elements->next);
	}
}

void	swap_b(t_container *container)
{
	t_stack	*stack;

	stack = container->stack2;
	if (2 <= stack->size)
	{
		swap_base(stack->elements, stack->elements->next);
	}
}

void	swap_ab(t_container *container)
{
	swap_a(container);
	swap_b(container);
}

static void	swap_base(t_list *list1, t_list *list2)
{
	t_list	*tmp;

	tmp = list1->content;
	list1->content = list2->content;
	list2->content = tmp;
}
