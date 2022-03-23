/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:02:16 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/24 00:02:25 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operators(t_list **operators)
{
	t_list	*operator;

	operator = *operators;
	while (operator != NULL)
	{
		ft_dprintf(1, "%s\n", (char *)operator->content);
		operator = operator->next;
	}
}
