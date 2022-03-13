/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_two_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:46:51 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/13 14:51:02 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show_stack(t_stack *stack, char *stack_name);

void	show_two_stacks(t_container *container)
{
	show_stack(container->stack1, "Stack A");
	show_stack(container->stack2, "Stack B");
}

static void	show_stack(t_stack *stack, char *stack_name)
{
	size_t	i;
	t_list	*node;

	ft_dprintf(1, "=============================\n");
	ft_dprintf(1, "========== %s ==========\n", stack_name);
	ft_dprintf(1, "=============================\n");
	i = 0;
	node = stack->elements;
	while (i < stack->size)
	{
		ft_dprintf(1, "%d: %2d\n", i, *(int *)node->content);
		node = node->next;
		i++;
	}
}
