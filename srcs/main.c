/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:42:12 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/13 00:33:36 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (is_valid_args(argc, argv))
	{
		/* Create and sort two stacks */
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "Error: Invalid arguments.\n");
		ft_dprintf(STDERR_FILENO, "Usage: push_swap <numbers>.\n");
		ft_dprintf(STDERR_FILENO, \
				"Numbers are integers and must not be duplicated.\n");
		return (1);
	}
	return (0);
}
