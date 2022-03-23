/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:42:08 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/23 08:49:44 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_integer(char	*s);
static bool	is_integer_all(int size, char **arr);
static bool	is_unique_all(int size, char **arr);

bool	is_valid_args(int size, char **args)
{
	if (size == 1)
		return (false);
	size--;
	args = &args[1];
	if (is_integer_all(size, args) && is_unique_all(size, args))
		return (true);
	return (false);
}

static bool	is_integer_all(int size, char **arr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_integer(arr[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_integer(char	*s)
{
	int			sign;
	size_t		i;
	long long	n;

	i = 0;
	sign = 1;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1] != '\0')
	{
		i++;
		sign = -1;
	}
	if (s[i] == '0' && s[i + 1] != '\0')
		return (false);
	n = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]))
			n = n * 10 + sign * (s[i] - '0');
		else
			return (false);
		if (n < (long long)INT_MIN || (long long)INT_MAX < n)
			return (false);
		i++;
	}
	return (true);
}

static bool	is_unique_all(int size, char **arr)
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
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
