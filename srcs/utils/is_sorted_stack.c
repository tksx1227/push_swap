/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:07:12 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/18 10:13:59 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted_stack(t_stack *stack)
{
	t_list	*node;

	if (stack->size <= 1)
		return (true);
	node = stack->elements;
	while (node->next != NULL)
	{
		if (*(int *)node->next->content < *(int *)node->content)
			return (false);
		node = node->next;
	}
	return (true);
}
