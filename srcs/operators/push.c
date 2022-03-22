/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:20:28 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 20:08:19 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_status	add_one_elem(t_stack *stack, int n);
static t_status	drop_one_elem(t_stack *stack);

void	push_stack_with_print(\
		t_stack *from_stack, t_stack *to_stack, bool need_print)
{
	t_status	status;

	if (0 < from_stack->size)
	{
		status = add_one_elem(to_stack, from_stack->elems[0]);
		if (status == SUCCESS)
			status = drop_one_elem(from_stack);
		if (status == FAIL)
		{
			free_two_stacks(&from_stack, &to_stack);
			exit(1);
		}
		if (need_print)
			print_operator(from_stack->name, "push");
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
