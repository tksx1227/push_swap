/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:48:21 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/21 19:22:49 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operator(char *from_stack_name, char *to_stack_name, char *operator_name)
{
	(void)to_stack_name;
	if (ft_strcmp(operator_name, "swap") == 0)
	{
		if (ft_strcmp(from_stack_name, "A") == 0)
			ft_dprintf(STDOUT_FILENO, "sa\n");
		else if (ft_strcmp(from_stack_name, "B") == 0)
			ft_dprintf(STDOUT_FILENO, "sb\n");
	}
	else if (ft_strcmp(operator_name, "push") == 0)
	{
		if (ft_strcmp(from_stack_name, "A") == 0)
			ft_dprintf(STDOUT_FILENO, "pb\n");
		else if (ft_strcmp(from_stack_name, "B") == 0)
			ft_dprintf(STDOUT_FILENO, "pa\n");
	}
	else if (ft_strcmp(operator_name, "rotate") == 0)
	{
		if (ft_strcmp(from_stack_name, "A") == 0)
			ft_dprintf(STDOUT_FILENO, "ra\n");
		else if (ft_strcmp(from_stack_name, "B") == 0)
			ft_dprintf(STDOUT_FILENO, "rb\n");
	}
	else if (ft_strcmp(operator_name, "rrotate") == 0)
	{
		if (ft_strcmp(from_stack_name, "A") == 0)
			ft_dprintf(STDOUT_FILENO, "rra\n");
		else if (ft_strcmp(from_stack_name, "B") == 0)
			ft_dprintf(STDOUT_FILENO, "rrb\n");
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "Error...\n");
	}
}
