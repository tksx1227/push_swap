/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:42:08 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/12 17:13:06 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_status	is_digit_all(int size, char **arr);
static t_status	is_integer(char	*s);
static t_status	is_unique_all(int size, char **arr);

t_status	is_valid_args(int size, char **args)
{
	if (size == 1)
	{
		return (FAIL);
	}
	size--;
	args = &args[1];
	if (is_digit_all(size, args) && is_unique_all(size, args))
	{
		return (SUCCESS);
	}
	return (FAIL);
}

static t_status	is_digit_all(int size, char **arr)
{
	int	i;

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
	int			i;
	int			sign;
	long long	n;

	i = 0;
	sign = 1;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1] != '\0')
	{
		i++;
		sign = -1;
	}
	if (s[i] == '0' && s[i + 1] != '\0')
		return (FAIL);
	n = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]))
			n = n * 10 + sign * (s[i] - '0');
		else
			return (FAIL);
		if (n < (long long)INT_MIN || (long long)INT_MAX < n)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static t_status	is_unique_all(int size, char **arr)
{
	int	n1;
	int	n2;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		n1 = ft_atoi(arr[i]);
		j = i + 1;
		while (j < size)
		{
			n2 = ft_atoi(arr[j]);
			if (n1 == n2)
				return (FAIL);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
