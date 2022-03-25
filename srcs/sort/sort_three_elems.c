/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elems.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:59:26 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/25 11:06:40 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_max_idx(int *arr, size_t size);

void	sort_three_elems(t_stack *stack, t_list **operators)
{
	size_t	max_idx;

	max_idx = get_max_idx(stack->elems, stack->size);
	if (max_idx == 0)
		rotate_and_set_operator(stack, operators);
	else if (max_idx == 1)
		rrotate_and_set_operator(stack, operators);
	if (stack->elems[1] < stack->elems[0])
		swap_and_set_operator(stack, operators);
}

static size_t	get_max_idx(int *arr, size_t size)
{
	size_t	i;
	size_t	max_idx;

	i = 0;
	max_idx = 0;
	while (i < size)
	{
		if (arr[max_idx] < arr[i])
			max_idx = i;
		i++;
	}
	return (max_idx);
}
