/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:48:21 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/22 18:05:52 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_swap(t_stack_name stack_name);
static void	print_push(t_stack_name stack_name);
static void	print_rotate(t_stack_name stack_name);
static void	print_rrotate(t_stack_name stack_name);

void	print_operator(t_stack_name stack_name, char *operator_name)
{
	if (ft_strcmp(operator_name, "swap") == 0)
		print_swap(stack_name);
	else if (ft_strcmp(operator_name, "push") == 0)
		print_push(stack_name);
	else if (ft_strcmp(operator_name, "rotate") == 0)
		print_rotate(stack_name);
	else if (ft_strcmp(operator_name, "rrotate") == 0)
		print_rrotate(stack_name);
}

static void	print_swap(t_stack_name stack_name)
{
	if (stack_name == STACK_A)
		ft_dprintf(STDOUT_FILENO, "sa\n");
	else if (stack_name == STACK_B)
		ft_dprintf(STDOUT_FILENO, "sb\n");
}

static void	print_push(t_stack_name stack_name)
{
	if (stack_name == STACK_A)
		ft_dprintf(STDOUT_FILENO, "pb\n");
	else if (stack_name == STACK_B)
		ft_dprintf(STDOUT_FILENO, "pa\n");
}

static void	print_rotate(t_stack_name stack_name)
{
	if (stack_name == STACK_A)
		ft_dprintf(STDOUT_FILENO, "ra\n");
	else if (stack_name == STACK_B)
		ft_dprintf(STDOUT_FILENO, "rb\n");
}

static void	print_rrotate(t_stack_name stack_name)
{
	if (stack_name == STACK_A)
		ft_dprintf(STDOUT_FILENO, "rra\n");
	else if (stack_name == STACK_B)
		ft_dprintf(STDOUT_FILENO, "rrb\n");
}
