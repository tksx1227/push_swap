/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:59:26 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/15 15:50:07 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case1_3_5(t_container *container, t_list **root, int num);
static void	case2_4(t_container *container, t_list **root, int num);

t_list	*sort_three_elem(t_container *container)
{
	t_list	*operators;
	int		first;
	int		second;
	int		third;

	first = *(int *)container->stack1->elements->content;
	second = *(int *)container->stack1->elements->next->content;
	third = *(int *)container->stack1->elements->next->next->content;
	operators = NULL;
	if (second < first && second < third && first < third)
		case1_3_5(container, &operators, 1);
	else if (third < second && second < first)
		case2_4(container, &operators, 2);
	else if (second < first && second < third && third < first)
		case1_3_5(container, &operators, 3);
	else if (first < second && third < second && first < third)
		case2_4(container, &operators, 4);
	else if (first < second && third < second && third < first)
		case1_3_5(container, &operators, 5);
	return (operators);
}

static void	case1_3_5(t_container *container, t_list **root, int num)
{
	t_list	*operator;

	if (num == 1)
	{
		swap_a(container);
		operator = ft_lstnew("sa");
	}
	else if (num == 3)
	{
		rotate_a(container);
		operator = ft_lstnew("ra");
	}
	else if (num == 5)
	{
		rrotate_a(container);
		operator = ft_lstnew("rra");
	}
	if (operator == NULL)
		exit(1);
	ft_lstadd_back(root, operator);
}

static void	case2_4(t_container *container, t_list **root, int num)
{
	t_list	*operator;

	if (num == 2)
	{
		swap_a(container);
		rrotate_a(container);
		operator = ft_lstnew("sa");
		if (operator == NULL)
			exit(1);
		ft_lstadd_back(root, operator);
		operator = ft_lstnew("rra");
	}
	else if (num == 4)
	{
		swap_a(container);
		rotate_a(container);
		operator = ft_lstnew("sa");
		if (operator == NULL)
			exit(1);
		ft_lstadd_back(root, operator);
		operator = ft_lstnew("ra");
	}
	if (operator == NULL)
		exit(1);
	ft_lstadd_back(root, operator);
}
