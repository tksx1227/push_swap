/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:09:45 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 19:23:51 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_checker.h"

void	push_swap_checker(int size, char **arr)
{
	t_status	status;
	t_stack		*stack1;
	t_stack		*stack2;

	stack1 = get_new_stack(size, arr);
	stack2 = get_new_stack(0, NULL);
	if (stack1 == NULL || stack2 == NULL)
	{
		free_stack(&stack1);
		free_stack(&stack2);
		exit(1);
	}
	status = do_check(stack1, stack2);
	free_stack(&stack1);
	free_stack(&stack2);
	if (status == FAIL)
		exit(1);
}
