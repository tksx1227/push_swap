/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:48:21 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/21 23:58:16 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_swap(char *stack_name);
static void	print_push(char *stack_name);
static void	print_rotate(char *stack_name);
static void	print_rrotate(char *stack_name);

void	print_operator(char *from_stack_name, char *to_stack_name, \
		char *operator_name)
{
	(void)to_stack_name;
	if (ft_strcmp(operator_name, "swap") == 0)
		print_swap(from_stack_name);
	else if (ft_strcmp(operator_name, "push") == 0)
		print_push(from_stack_name);
	else if (ft_strcmp(operator_name, "rotate") == 0)
		print_rotate(from_stack_name);
	else if (ft_strcmp(operator_name, "rrotate") == 0)
		print_rrotate(from_stack_name);
}

static void	print_swap(char *stack_name)
{
	if (ft_strcmp(stack_name, "A") == 0)
		ft_dprintf(STDOUT_FILENO, "sa\n");
	else if (ft_strcmp(stack_name, "B") == 0)
		ft_dprintf(STDOUT_FILENO, "sb\n");
}

static void	print_push(char *stack_name)
{
	if (ft_strcmp(stack_name, "A") == 0)
		ft_dprintf(STDOUT_FILENO, "pb\n");
	else if (ft_strcmp(stack_name, "B") == 0)
		ft_dprintf(STDOUT_FILENO, "pa\n");
}

static void	print_rotate(char *stack_name)
{
	if (ft_strcmp(stack_name, "A") == 0)
		ft_dprintf(STDOUT_FILENO, "ra\n");
	else if (ft_strcmp(stack_name, "B") == 0)
		ft_dprintf(STDOUT_FILENO, "rb\n");
}

static void	print_rrotate(char *stack_name)
{
	if (ft_strcmp(stack_name, "A") == 0)
		ft_dprintf(STDOUT_FILENO, "rra\n");
	else if (ft_strcmp(stack_name, "B") == 0)
		ft_dprintf(STDOUT_FILENO, "rrb\n");
}
