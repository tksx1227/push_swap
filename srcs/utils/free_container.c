/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_container.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:22:59 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/13 14:31:59 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack);

void	free_container(t_container *container)
{
	free_stack(container->stack1);
	free_stack(container->stack2);
	free(container);
}

static void	free_stack(t_stack *stack)
{
	ft_lstclear(&(stack->elements), free);
	free(stack);
}
