/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:55:34 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/24 08:29:10 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_and_set_operator(t_stack *stack, t_list **operators)
{
	int		tmp;
	t_list	*new_operator;

	if (2 <= stack->size)
	{
		tmp = stack->elems[0];
		stack->elems[0] = stack->elems[1];
		stack->elems[1] = tmp;
		if (operators != NULL)
		{
			if (stack->name == STACK_A)
				new_operator = ft_lstnew("sa");
			else
				new_operator = ft_lstnew("sb");
			if (new_operator == NULL)
				exit(1);
			ft_lstadd_back(operators, new_operator);
		}
	}
}

void	swap_double_and_set_operator(t_stack *stack1, t_stack *stack2, \
		t_list **operators)
{
	swap_and_set_operator(stack1, operators);
	swap_and_set_operator(stack2, operators);
}
