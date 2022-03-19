/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:14:43 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 13:15:56 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_operators(t_list *operators)
{
	t_list	*node;

	node = operators;
	while (node != NULL)
	{
		ft_dprintf(STDOUT_FILENO, "%s\n", (char *)node->content);
		node = node->next;
	}
}
