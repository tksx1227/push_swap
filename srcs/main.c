/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:42:12 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/13 14:55:40 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_container	*container;

	if (is_valid_args(argc, argv))
	{
		container = get_new_container(argc - 1, &argv[1]);
		/* Sort two stacks */
		free_container(container);
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
