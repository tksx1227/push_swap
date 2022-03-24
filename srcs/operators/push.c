/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:20:28 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/24 08:52:09 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_status	add_one_elem(t_stack *stack, int n);
static t_status	drop_one_elem(t_stack *stack);

void	push_and_set_operator(\
		t_stack *from_stack, t_stack *to_stack, t_list **operators)
{
	t_list		*new_operator;
	t_status	status;

	if (0 < from_stack->size)
	{
		status = add_one_elem(to_stack, from_stack->elems[0]);
		if (status == SUCCESS)
			status = drop_one_elem(from_stack);
		if (status == FAIL)
			exit(1);
		if (operators != NULL)
		{
			if (from_stack->name == STACK_A)
				new_operator = ft_lstnew("pb");
			else
				new_operator = ft_lstnew("pa");
			if (new_operator == NULL)
				exit(1);
			ft_lstadd_back(operators, new_operator);
		}
	}
}

static t_status	add_one_elem(t_stack *stack, int n)
{
	size_t	i;
	int		*new_elems;

	new_elems = (int *)malloc(sizeof(int) * (stack->size + 1));
	if (new_elems == NULL)
		return (FAIL);
	i = 0;
	new_elems[i] = n;
	while (i < stack->size)
	{
		new_elems[i + 1] = stack->elems[i];
		i++;
	}
	free(stack->elems);
	stack->elems = new_elems;
	stack->size++;
	return (SUCCESS);
}

static t_status	drop_one_elem(t_stack *stack)
{
	size_t	i;
	int		*new_elems;

	new_elems = (int *)malloc(sizeof(int) * (stack->size - 1));
	if (new_elems == NULL)
		return (FAIL);
	i = 0;
	while (i < stack->size - 1)
	{
		new_elems[i] = stack->elems[i + 1];
		i++;
	}
	free(stack->elems);
	stack->elems = new_elems;
	stack->size--;
	return (SUCCESS);
}
