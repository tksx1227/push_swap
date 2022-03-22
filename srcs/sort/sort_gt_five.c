/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_gt_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:46:24 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 20:11:26 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_recursion_for_stack_a(\
		t_stack *from_stack, t_stack *to_stack, size_t origin_size);
static void	sort_recursion_for_stack_b(\
		t_stack *from_stack, t_stack *to_stack, size_t origin_chunk_size);
static void	move_gt_mid(\
		t_stack *from_stack, t_stack *to_stack, size_t chunk_size);
static void	move_lt_mid(\
		t_stack *from_stack, t_stack *to_stack, size_t chunk_size);
static void	reverse_rotate_stack(\
		t_stack *stack, bool need_rotate, size_t rotate_count);

void	sort_gt_five(t_stack *stack1, t_stack *stack2)
{
	sort_recursion_for_stack_a(stack1, stack2, stack1->size);
}

static void	sort_recursion_for_stack_a(\
		t_stack *from_stack, t_stack *to_stack, size_t origin_size)
{
	size_t	left_chunk_size;
	size_t	moved_chunk_size;

	if (origin_size < 3)
	{
		if (origin_size == 2 && from_stack->elems[1] < from_stack->elems[0])
			swap_one_stack_with_print(from_stack, true);
		return ;
	}
	moved_chunk_size = origin_size / 2;
	left_chunk_size = origin_size - moved_chunk_size;
	move_lt_mid(from_stack, to_stack, origin_size);
	sort_recursion_for_stack_a(from_stack, to_stack, left_chunk_size);
	sort_recursion_for_stack_b(to_stack, from_stack, moved_chunk_size);
}

static void	sort_recursion_for_stack_b(\
		t_stack *from_stack, t_stack *to_stack, size_t origin_size)
{
	size_t	i;
	size_t	left_chunk_size;
	size_t	moved_chunk_size;

	if (origin_size < 3)
	{
		if (origin_size == 2 && from_stack->elems[0] < from_stack->elems[1])
			swap_one_stack_with_print(from_stack, true);
		i = 0;
		while (i < origin_size)
		{
			push_stack_with_print(from_stack, to_stack, true);
			i++;
		}
		return ;
	}
	moved_chunk_size = origin_size / 2;
	left_chunk_size = origin_size - moved_chunk_size;
	move_gt_mid(from_stack, to_stack, origin_size);
	sort_recursion_for_stack_a(to_stack, from_stack, moved_chunk_size);
	sort_recursion_for_stack_b(from_stack, to_stack, left_chunk_size);
}

static void	move_gt_mid(\
		t_stack *from_stack, t_stack *to_stack, size_t chunk_size)
{
	int		mid_val;
	bool	need_reverse_rotate;
	size_t	i;
	size_t	rotate_count;

	i = 0;
	rotate_count = 0;
	need_reverse_rotate = true;
	if (chunk_size == from_stack->size)
		need_reverse_rotate = false;
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
	reverse_rotate_stack(from_stack, need_reverse_rotate, rotate_count);
}

static void	move_lt_mid(\
		t_stack *from_stack, t_stack *to_stack, size_t chunk_size)
{
	int		mid_val;
	bool	need_reverse_rotate;
	size_t	i;
	size_t	rotate_count;

	i = 0;
	rotate_count = 0;
	need_reverse_rotate = true;
	if (chunk_size == from_stack->size)
		need_reverse_rotate = false;
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
	reverse_rotate_stack(from_stack, need_reverse_rotate, rotate_count);
}

static void	reverse_rotate_stack(t_stack *stack, bool need_rotate, size_t rotate_count)
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
