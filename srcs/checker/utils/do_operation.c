/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:23:14 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/24 09:26:32 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

t_status	do_operation(t_stack *stack1, t_stack *stack2, char *operator)
{
	if (ft_strcmp(operator, "sa\n") == 0)
		swap_and_set_operator(stack1, NULL);
	else if (ft_strcmp(operator, "sb\n") == 0)
		swap_and_set_operator(stack2, NULL);
	else if (ft_strcmp(operator, "ss\n") == 0)
		swap_double_and_set_operator(stack1, stack2, NULL);
	else if (ft_strcmp(operator, "pa\n") == 0)
		push_and_set_operator(stack2, stack1, NULL);
	else if (ft_strcmp(operator, "pb\n") == 0)
		push_and_set_operator(stack1, stack2, NULL);
	else if (ft_strcmp(operator, "ra\n") == 0)
		rotate_and_set_operator(stack1, NULL);
	else if (ft_strcmp(operator, "rb\n") == 0)
		rotate_and_set_operator(stack2, NULL);
	else if (ft_strcmp(operator, "rr\n") == 0)
		rotate_double_and_set_operator(stack1, stack2, NULL);
	else if (ft_strcmp(operator, "rra\n") == 0)
		rrotate_and_set_operator(stack1, NULL);
	else if (ft_strcmp(operator, "rrb\n") == 0)
		rrotate_and_set_operator(stack2, NULL);
	else if (ft_strcmp(operator, "rrr\n") == 0)
		rrotate_double_and_set_operator(stack1, stack2, NULL);
	else
		return (FAIL);
	return (SUCCESS);
}
