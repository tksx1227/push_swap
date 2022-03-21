/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mid_from_sequence.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:29:50 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/21 18:29:59 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_mid_from_sequence(int *arr, size_t size)
{
	size_t		i;
	int			mid_val;
	long long	min_val;
	long long	max_val;

	i = 0;
	min_val = arr[0];
	max_val = arr[0];
	while (i < size)
	{
		if (arr[i] < min_val)
			min_val = arr[i];
		if (max_val < arr[i])
			max_val = arr[i];
		i++;
	}
	mid_val = (max_val + min_val + 1) / 2;
	return (mid_val);
}
