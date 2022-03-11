/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:34:58 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/11 15:15:45 by ttomori          ###   ########.fr       */
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
	t_list	*new;

	if (0 < stack->size)
	{
		new = ft_lstnew(stack->elements->content);
		ft_lstadd_back(&(stack->elements), new);
		stack->elements = stack->elements->next;
		// freeになる予定
		ft_lstdelone(stack->elements->prev, NULL);
		stack->elements->prev = NULL;
	}
}
