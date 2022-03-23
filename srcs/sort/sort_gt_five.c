/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_gt_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:46:24 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/23 23:40:05 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_gt_five(t_stack *stack1, t_stack *stack2, t_list **operators)
{
	sort_recursive_for_stack_a(stack1, stack2, stack1->size, operators);
}
