/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:48:18 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 18:48:50 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

char	*ft_strndup(const char *s, size_t size)
{
	size_t	i;
	size_t	len;
	char	*p;

	len = ft_strlen(s);
	if (len < size)
		size = len;
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (p == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strchr_null_safe(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_with_free(char *s1, char *s2)
{
	size_t	len[2];
	char	*p;
	char	*temp;
	char	*head;

	if (s1 == NULL)
		return (ft_strndup(s2, ft_strlen(s2)));
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	if (SIZE_MAX - len[0] <= len[1])
	{
		free(s1);
		return (NULL);
	}
	p = (char *)malloc(sizeof(char) * (len[0] + len[1] + 1));
	head = p;
	temp = s1;
	while (p != NULL && *s1 != '\0')
		*p++ = *s1++;
	while (p != NULL && *s2 != '\0')
		*p++ = *s2++;
	if (p != NULL)
		*p = '\0';
	free(temp);
	return (head);
}

t_node	*gnl_new_node(int fd)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->storage = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
