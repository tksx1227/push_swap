/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_recursive_for_stack_a.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:36:20 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/23 23:41:37 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_recursive_for_stack_a(t_stack *from_stack, t_stack *to_stack, \
		size_t origin_size, t_list **operators)
{
	size_t	left_chunk_size;
	size_t	moved_chunk_size;

	if (origin_size < 3)
	{
		if (origin_size == 2 && from_stack->elems[1] < from_stack->elems[0])
			swap_and_set_operator(from_stack, operators);
		return ;
	}
	moved_chunk_size = origin_size / 2;
	left_chunk_size = origin_size - moved_chunk_size;
	move_lt_mid(from_stack, to_stack, origin_size, operators);
	sort_recursive_for_stack_a(\
			from_stack, to_stack, left_chunk_size, operators);
	sort_recursive_for_stack_b(\
			to_stack, from_stack, moved_chunk_size, operators);
}
