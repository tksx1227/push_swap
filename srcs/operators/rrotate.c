/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:34:58 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/11 16:05:42 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate_base(t_stack *stack);

void	rrotate_a(t_container *container)
{
	rrotate_base(container->stack1);
}

void	rrotate_b(t_container *container)
{
	rrotate_base(container->stack2);
}

void	rrotate_ab(t_container *container)
{
	rrotate_a(container);
	rrotate_b(container);
}

static void	rrotate_base(t_stack *stack)
{
	t_list	*tail;

	if (2 <= stack->size)
	{
		tail = ft_lstlast(stack->elements);
		tail->prev->next = NULL;
		tail->prev = NULL;
		tail->next = NULL;
		ft_lstadd_front(&(stack->elements), tail);
	}
}
