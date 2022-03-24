/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:09:45 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/24 09:36:05 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	push_swap_checker(int size, char **arr)
{
	t_stack		*stack1;
	t_stack		*stack2;

	stack1 = get_new_stack(size, arr, STACK_A);
	stack2 = get_new_stack(0, NULL, STACK_B);
	if (stack1 == NULL || stack2 == NULL)
		exit(1);
	do_check(stack1, stack2);
	free_two_stacks(&stack1, &stack2);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	else if (is_valid_args(argc, argv))
		push_swap_checker(argc - 1, &argv[1]);
	else
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (1);
	}
	return (0);
}
