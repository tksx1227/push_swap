/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:22:59 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 12:44:38 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	if (stack != NULL)
	{
		free((*stack)->elems);
		free(*stack);
		*stack = NULL;
	}
}

void	free_two_stacks(t_stack **stack1, t_stack **stack2)
{
	free_stack(stack1);
	free_stack(stack2);
}
