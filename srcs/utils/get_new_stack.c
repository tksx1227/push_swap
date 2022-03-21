/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 00:45:39 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/21 18:47:33 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*convert_to_numbers(int size, char **arr);

t_stack	*get_new_stack(int size, char **arr, char *name)
{
	int		*elems;
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	if (arr == NULL)
	{
		stack->size = 0;
		stack->elems = NULL;
	}
	else
	{
		elems = convert_to_numbers(size, arr);
		if (elems == NULL)
		{
			free(stack);
			return (NULL);
		}
		stack->size = size;
		stack->elems = elems;
	}
	stack->name = name;
	return (stack);
}

static int	*convert_to_numbers(int size, char **arr)
{
	int	i;
	int	*numbers;

	numbers = (int *)malloc(sizeof(int) * size);
	if (numbers == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		numbers[i] = ft_atoi(arr[i]);
		i++;
	}
	return (numbers);
}
