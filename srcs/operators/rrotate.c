/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:34:58 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/24 08:30:39 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_and_set_operator(t_stack *stack, t_list **operators)
{
	size_t	i;
	int		last_num;
	t_list	*new_operator;

	if (2 <= stack->size)
	{
		i = stack->size - 1;
		last_num = stack->elems[i];
		while (0 < i)
		{
			stack->elems[i] = stack->elems[i - 1];
			i--;
		}
		stack->elems[i] = last_num;
		if (operators != NULL)
		{
			if (stack->name == STACK_A)
				new_operator = ft_lstnew("rra");
			else
				new_operator = ft_lstnew("rrb");
			if (new_operator == NULL)
				exit(1);
			ft_lstadd_back(operators, new_operator);
		}
	}
}

void	rrotate_double_and_set_operator(t_stack *stack1, t_stack *stack2, \
		t_list **operators)
{
	rrotate_and_set_operator(stack1, operators);
	rrotate_and_set_operator(stack2, operators);
}
