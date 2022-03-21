/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_two_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:46:51 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/21 23:47:00 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_stack *stack)
{
	size_t	i;

	ft_dprintf(1, "=============================\n");
	ft_dprintf(1, "============ %s ============\n", stack->name);
	ft_dprintf(1, "=============================\n");
	i = 0;
	while (i < stack->size)
	{
		ft_dprintf(1, "%02d: %2d\n", i, stack->elems[i]);
		i++;
	}
}
