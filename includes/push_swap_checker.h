/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:13:21 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/21 19:19:23 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# define BUFFER_SIZE 512

# include "push_swap.h"

typedef struct s_node
{
	int				fd;
	char			*storage;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// gnl functions
char		*get_next_line(int fd);
int			gnl_read(t_node	*node);
char		*gnl_reformat_line(t_node *node);
void		gnl_free(t_node **root, t_node *target);
t_node		*gnl_get_node(int fd, t_node **root);
t_node		*gnl_new_node(int fd);

// util functions
char		*ft_strchr_null_safe(const char *s, int c);
char		*ft_strndup(const char *s, size_t size);
char		*ft_strjoin_with_free(char *s1, char *s2);

// checker
bool		is_valid_operator(char *line);
void		push_swap_checker(int size, char **arr);
t_status	do_check(t_stack *stack1, t_stack *stack2);
t_status	do_operation(t_stack *stack1, t_stack *stack2, char *operator);

#endif
