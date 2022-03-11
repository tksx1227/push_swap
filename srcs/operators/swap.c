/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:55:34 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/11 15:14:07 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_base(t_stack *stack);

void	swap_a(t_container *container)
{
	swap_base(container->stack1);
}

void	swap_b(t_container *container)
{
	swap_base(container->stack2);
}

void	swap_ab(t_container *container)
{
	swap_a(container);
	swap_b(container);
}

static void	swap_base(t_stack *stack)
{
	void	*tmp;

	if (2 <= stack->size)
	{
		tmp = stack->elements->content;
		stack->elements->content = stack->elements->next->content;
		stack->elements->next->content = tmp;
	}
}
