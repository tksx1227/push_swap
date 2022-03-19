/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:19:56 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 18:48:33 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

char	*get_next_line(int fd)
{
	int				status;
	char			*line;
	t_node			*node;
	static t_node	*root;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (root == NULL)
	{
		root = gnl_new_node(fd);
		if (root == NULL)
			return (NULL);
	}
	node = gnl_get_node(fd, &root);
	status = gnl_read(node);
	if (status == FAIL)
	{
		gnl_free(&root, node);
		return (NULL);
	}
	line = gnl_reformat_line(node);
	if (line == NULL || *(node->storage) == '\0')
		gnl_free(&root, node);
	return (line);
}

int	gnl_read(t_node	*node)
{
	ssize_t	rc;
	char	*buf;

	if (node == NULL)
		return (FAIL);
	while (1)
	{
		if (ft_strchr_null_safe(node->storage, '\n') != NULL)
			return (SUCCESS);
		buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		rc = read(node->fd, buf, BUFFER_SIZE);
		if (rc == -1 || rc == 0)
		{
			free(buf);
			if (rc == 0)
				return (SUCCESS);
			return (FAIL);
		}
		buf[rc] = '\0';
		node->storage = ft_strjoin_with_free(node->storage, buf);
		free(buf);
		if (node->storage == NULL)
			return (FAIL);
	}
}

t_node	*gnl_get_node(int fd, t_node **root)
{
	t_node	*node;
	t_node	*prev;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		node = gnl_new_node(fd);
		*root = node;
		return (node);
	}
	node = *root;
	while (node != NULL)
	{
		if (node->fd == fd)
			return (node);
		prev = node;
		node = node->next;
	}
	node = gnl_new_node(fd);
	prev->next = node;
	node->prev = prev;
	return (node);
}

char	*gnl_reformat_line(t_node *node)
{
	char	*temp;
	char	*line;
	char	*target;

	if (node == NULL)
		return (NULL);
	target = ft_strchr_null_safe(node->storage, '\n');
	if (target == NULL)
	{
		line = node->storage;
		node->storage = ft_strndup("", 0);
		return (line);
	}
	temp = node->storage;
	line = ft_strndup(temp, target - temp + 1);
	node->storage = ft_strndup(target + 1, ft_strlen(target + 1));
	free(temp);
	if (node->storage == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	gnl_free(t_node **root, t_node *target)
{
	t_node	*prev;
	t_node	*next;

	if (root == NULL || *root == NULL || target == NULL)
		return ;
	prev = target->prev;
	next = target->next;
	if (prev != NULL)
	{
		prev->next = next;
		if (next != NULL)
			next->prev = prev;
	}
	else
	{
		*root = next;
		if (next != NULL)
			next->prev = NULL;
	}
	free(target->storage);
	free(target);
}
