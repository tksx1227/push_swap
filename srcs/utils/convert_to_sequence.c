/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_sequence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 23:13:08 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 19:24:46 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_intmax_idx(int *arr, size_t size);
static size_t	get_min_idx(int	*arr, size_t size);
static void		set_sequence_num(t_stack *stack, int *idx_arr);

t_status	convert_to_sequence(t_stack *stack)
{
	int		intmax_idx;
	int		*idx_arr;
	size_t	i;
	size_t	min_idx;

	idx_arr = (int *)malloc(sizeof(int) * stack->size);
	if (idx_arr == NULL)
		return (FAIL);
	intmax_idx = get_intmax_idx(stack->elems, stack->size);
	i = 0;
	while (i < stack->size)
	{
		min_idx = get_min_idx(stack->elems, stack->size);
		stack->elems[min_idx] = INT_MAX;
		idx_arr[i] = min_idx;
		i++;
	}
	if (0 <= intmax_idx)
		idx_arr[stack->size - 1] = intmax_idx;
	set_sequence_num(stack, idx_arr);
	free(idx_arr);
	return (SUCCESS);
}

static int	get_intmax_idx(int *arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == INT_MAX)
			return (i);
		i++;
	}
	return (-1);
}

static size_t	get_min_idx(int	*arr, size_t size)
{
	size_t	i;
	size_t	min_idx;

	i = 0;
	min_idx = 0;
	while (i < size)
	{
		if (arr[i] < arr[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

static void	set_sequence_num(t_stack *stack, int *idx_arr)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		stack->elems[idx_arr[i]] = i;
		i++;
	}
}
