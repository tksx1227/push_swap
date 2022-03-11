/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:20:28 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/11 14:53:23 by ttomori          ###   ########.fr       */
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
	t_list	*new;

	if (0 <= from_stack->size)
	{
		new = ft_lstnew(from_stack->elements->content);
		if (new == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Error\n");
			exit(1);
		}
		ft_lstadd_front(&(to_stack->elements), new);
		from_stack->elements = from_stack->elements->next;
		ft_lstdelone(from_stack->elements->prev, NULL);
		from_stack->elements->prev = NULL;
		to_stack->size++;
		from_stack->size--;
	}
}
