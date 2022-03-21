/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:23:14 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/21 23:43:05 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

t_status	do_operation(t_stack *stack1, t_stack *stack2, char *operator)
{
	if (ft_strcmp(operator, "sa\n") == 0)
		swap_one_stack(stack1);
	else if (ft_strcmp(operator, "sb\n") == 0)
		swap_one_stack(stack2);
	else if (ft_strcmp(operator, "ss\n") == 0)
		swap_two_stacks(stack1, stack2);
	else if (ft_strcmp(operator, "pa\n") == 0)
		push_stack(stack2, stack1);
	else if (ft_strcmp(operator, "pb\n") == 0)
		push_stack(stack1, stack2);
	else if (ft_strcmp(operator, "ra\n") == 0)
		rotate_one_stack(stack1);
	else if (ft_strcmp(operator, "rb\n") == 0)
		rotate_one_stack(stack2);
	else if (ft_strcmp(operator, "rr\n") == 0)
		rotate_two_stacks(stack1, stack2);
	else if (ft_strcmp(operator, "rra\n") == 0)
		rrotate_one_stack(stack1);
	else if (ft_strcmp(operator, "rrb\n") == 0)
		rrotate_one_stack(stack2);
	else if (ft_strcmp(operator, "rra\n") == 0)
		rrotate_two_stacks(stack1, stack2);
	else
		return (FAIL);
	return (SUCCESS);
}
