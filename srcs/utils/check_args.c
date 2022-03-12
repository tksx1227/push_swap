/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:42:08 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/12 16:06:29 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_status	is_digit_all(size_t size, char **arr);
static t_status	is_integer(char	*s);

static t_status	is_digit_all(size_t size, char **arr)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (!is_integer(arr[i]))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static t_status	is_integer(char	*s)
{
	size_t	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '0' && s[i + 1] != '\0')
		return (FAIL);
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}
