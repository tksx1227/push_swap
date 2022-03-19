/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:22:32 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 19:22:56 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

bool	is_valid_operator(char *line)
{
	if (ft_strcmp(line, "sa\n") == 0 \
			|| ft_strcmp(line, "sb\n") == 0 \
			|| ft_strcmp(line, "ss\n") == 0 \
			|| ft_strcmp(line, "pa\n") == 0 \
			|| ft_strcmp(line, "pb\n") == 0 \
			|| ft_strcmp(line, "ra\n") == 0 \
			|| ft_strcmp(line, "rb\n") == 0 \
			|| ft_strcmp(line, "rr\n") == 0 \
			|| ft_strcmp(line, "rra\n") == 0 \
			|| ft_strcmp(line, "rrb\n") == 0 \
			|| ft_strcmp(line, "rrr\n") == 0)
		return (true);
	return (false);
}
