/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_two_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:46:51 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 12:06:48 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_stack *stack, char *stack_name)
{
	size_t	i;

	ft_dprintf(1, "=============================\n");
	ft_dprintf(1, "========== %s ==========\n", stack_name);
	ft_dprintf(1, "=============================\n");
	i = 0;
	while (i < stack->size)
	{
		ft_dprintf(1, "%d: %2d\n", i, stack->elems[i]);
		i++;
	}
}
