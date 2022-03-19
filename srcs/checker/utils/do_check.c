/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:23:57 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 19:32:19 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

t_status	do_check(t_stack *stack1, t_stack *stack2)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (!is_valid_operator(line) || \
				do_operation(stack1, stack2, line) == FAIL)
		{
			free(line);
			ft_dprintf(STDERR_FILENO, "Error\n");
			return (FAIL);
		}
		free(line);
	}
	if (is_sorted_stack(stack1))
		ft_dprintf(STDOUT_FILENO, "OK\n");
	else
		ft_dprintf(STDOUT_FILENO, "KO\n");
	return (SUCCESS);
}
