/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_le_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:21:29 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 20:04:53 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_le_five(t_stack *stack1, t_stack *stack2)
{
	if (stack1->size == 5)
		sort_five_elems(stack1, stack2);
	else if (stack1->size == 4)
		sort_four_elems(stack1, stack2);
	else if (stack1->size == 3)
		sort_three_elems(stack1);
	else if (stack1->size == 2)
	{
		if (stack1->elems[1] < stack1->elems[0])
			swap_one_stack_with_print(stack1, true);
	}
}
