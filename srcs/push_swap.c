/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:20:12 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/24 08:50:25 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int size, char **arr)
{
	t_list	*operators;
	t_stack	*stack1;
	t_stack	*stack2;

	operators = (t_list *)malloc(sizeof(t_list));
	stack1 = get_new_stack(size, arr, STACK_A);
	stack2 = get_new_stack(0, NULL, STACK_B);
	if (operators == NULL || stack1 == NULL || stack2 == NULL)
		exit(1);
	if (!is_sorted_stack(stack1))
	{
		operators = NULL;
		convert_to_sequence(stack1);
		if (stack1->size <= 5)
			sort_le_five(stack1, stack2, &operators);
		else
			sort_gt_five(stack1, stack2, &operators);
		print_operators(&operators);
	}
	free_two_stacks(&stack1, &stack2);
	ft_lstclear(&operators, NULL);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	else if (is_valid_args(argc, argv))
		push_swap(argc - 1, &argv[1]);
	else
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (1);
	}
	return (0);
}
