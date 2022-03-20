/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:09:45 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/20 15:21:32 by ttomori          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		return (0);
	}
	else if (is_valid_args(argc, argv))
	{
		push_swap_checker(argc - 1, &argv[1]);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (1);
	}
	return (0);
}
