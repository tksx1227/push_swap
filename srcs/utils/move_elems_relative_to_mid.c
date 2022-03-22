/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elems_relative_to_mid.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:08:12 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 23:10:14 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	get_need_reverse_rotate_flag(size_t stack_size, size_t chunk_size);
static void	rrotate_n_times(\
		t_stack *stack, bool need_rotate, size_t rotate_count);

void	move_lt_mid(t_stack *from_stack, t_stack *to_stack, size_t chunk_size)
{
	int		mid_val;
	bool	need_reverse_rotate;
	size_t	i;
	size_t	rotate_count;

	i = 0;
	rotate_count = 0;
	need_reverse_rotate = get_need_reverse_rotate_flag(\
			from_stack->size, chunk_size);
	mid_val = get_mid_from_sequence(from_stack->elems, chunk_size);
	while (i < chunk_size / 2)
	{
		if (*from_stack->elems < mid_val)
		{
			push_stack_with_print(from_stack, to_stack, true);
			i++;
		}
		else
		{
			rotate_one_stack_with_print(from_stack, true);
			rotate_count++;
		}
	}
	rrotate_n_times(from_stack, need_reverse_rotate, rotate_count);
}

void	move_gt_mid(t_stack *from_stack, t_stack *to_stack, size_t chunk_size)
{
	int		mid_val;
	bool	need_reverse_rotate;
	size_t	i;
	size_t	rotate_count;

	i = 0;
	rotate_count = 0;
	need_reverse_rotate = get_need_reverse_rotate_flag(\
			from_stack->size, chunk_size);
	mid_val = get_mid_from_sequence(from_stack->elems, chunk_size);
	while (i < chunk_size / 2)
	{
		if (mid_val < *from_stack->elems \
				|| (chunk_size % 2 == 0 && mid_val <= *from_stack->elems))
		{
			push_stack_with_print(from_stack, to_stack, true);
			i++;
		}
		else
		{
			rotate_one_stack_with_print(from_stack, true);
			rotate_count++;
		}
	}
	rrotate_n_times(from_stack, need_reverse_rotate, rotate_count);
}

static bool	get_need_reverse_rotate_flag(size_t stack_size, size_t chunk_size)
{
	bool	need_reverse_rotate;

	need_reverse_rotate = true;
	if (chunk_size == stack_size)
		need_reverse_rotate = false;
	return (need_reverse_rotate);
}

static void	rrotate_n_times(\
		t_stack *stack, bool need_rotate, size_t rotate_count)
{
	size_t	i;

	if (need_rotate)
	{
		i = 0;
		while (i < rotate_count)
		{
			rrotate_one_stack_with_print(stack, true);
			i++;
		}
	}
}
