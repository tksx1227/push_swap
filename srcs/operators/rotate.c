/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:34:58 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/24 08:30:19 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_and_set_operator(t_stack *stack, t_list **operators)
{
	size_t	i;
	int		first_num;
	t_list	*new_operator;

	if (2 <= stack->size)
	{
		i = 0;
		first_num = stack->elems[i];
		while (i < stack->size - 1)
		{
			stack->elems[i] = stack->elems[i + 1];
			i++;
		}
		stack->elems[i] = first_num;
		if (operators != NULL)
		{
			if (stack->name == STACK_A)
				new_operator = ft_lstnew("ra");
			else
				new_operator = ft_lstnew("rb");
			if (new_operator == NULL)
				exit(1);
			ft_lstadd_back(operators, new_operator);
		}
	}
}

void	rotate_double_and_set_operator(t_stack *stack1, t_stack *stack2, \
		t_list **operators)
{
	rotate_and_set_operator(stack1, operators);
	rotate_and_set_operator(stack2, operators);
}
