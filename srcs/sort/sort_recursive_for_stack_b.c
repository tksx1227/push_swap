/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_recursive_for_stack_b.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:57:03 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 23:10:34 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_recursive_for_stack_b(\
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
	sort_recursive_for_stack_a(to_stack, from_stack, moved_chunk_size);
	sort_recursive_for_stack_b(from_stack, to_stack, left_chunk_size);
}
