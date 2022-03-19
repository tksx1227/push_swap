/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:20:28 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 12:56:35 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_one_elem(t_stack *stack, int n);
static void	drop_one_elem(t_stack *stack);

void	push_stack(t_stack *from_stack, t_stack *to_stack)
{
	if (0 < from_stack->size)
	{
		add_one_elem(to_stack, from_stack->elems[0]);
		drop_one_elem(from_stack);
	}
}

static void	add_one_elem(t_stack *stack, int n)
{
	size_t	i;
	int		*new_elems;

	new_elems = (int *)malloc(sizeof(int) * (stack->size + 1));
	if (new_elems == NULL)
		exit(2);
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
}

static void	drop_one_elem(t_stack *stack)
{
	size_t	i;
	int		*new_elems;

	new_elems = (int *)malloc(sizeof(int) * (stack->size - 1));
	if (new_elems == NULL)
		exit(2);
	i = 0;
	while (i < stack->size - 1)
	{
		new_elems[i] = stack->elems[i + 1];
		i++;
	}
	free(stack->elems);
	stack->elems = new_elems;
	stack->size--;
}
