/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_container.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 00:45:39 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/13 14:22:10 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_new_stack(int size, void *content);
static t_list	*get_one_node(int n);
static int		*convert_to_numbers(int size, char **arr);

t_container	*get_new_container(int size, char **arr)
{
	int			*numbers;
	t_container	*container;

	container = (t_container *)malloc(sizeof(t_container));
	if (container == NULL)
		return (NULL);
	numbers = convert_to_numbers(size, arr);
	if (numbers == NULL)
	{
		free(container);
		return (NULL);
	}
	container->stack1 = get_new_stack(size, numbers);
	container->stack2 = get_new_stack(0, NULL);
	free(numbers);
	if (container->stack1 == NULL || container->stack2 == NULL)
	{
		free(container->stack1);
		free(container->stack2);
		free(container);
		return (NULL);
	}
	return (container);
}

static t_stack	*get_new_stack(int size, void *content)
{
	int		i;
	t_list	*node;
	t_list	*head;
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	i = 0;
	head = NULL;
	while (i < size)
	{
		node = get_one_node(((int *)content)[i]);
		if (node == NULL)
		{
			free(stack);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		i++;
	}
	stack->size = size;
	stack->elements = head;
	return (stack);
}

static t_list	*get_one_node(int n)
{
	int		*ptr;
	t_list	*node;

	ptr = (int *)malloc(sizeof(int));
	if (ptr == NULL)
		return (NULL);
	*ptr = n;
	node = ft_lstnew(ptr);
	if (node == NULL)
	{
		free(ptr);
		return (NULL);
	}
	return (node);
}

static int	*convert_to_numbers(int size, char **arr)
{
	int	i;
	int	*numbers;

	numbers = (int *)malloc(sizeof(int) * size);
	if (numbers == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		numbers[i] = ft_atoi(arr[i]);
		i++;
	}
	return (numbers);
}
