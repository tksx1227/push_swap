/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:59:26 by ttomori           #+#    #+#             */
/*   Updated: 2022/03/19 12:48:10 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case1_3_5(t_stack *stack, t_stack *stack2, t_list **root, int num);
static void	case2_4(t_stack *stack1, t_stack *stack2, t_list **root, int num);

t_list	*sort_three_elem(t_stack *stack1, t_stack *stack2)
{
	t_list	*operators;
	int		first;
	int		second;
	int		third;

	first = stack1->elems[0];
	second = stack1->elems[1];
	third = stack1->elems[2];
	operators = NULL;
	if (second < first && second < third && first < third)
		case1_3_5(stack1, stack2, &operators, 1);
	else if (third < second && second < first)
		case2_4(stack1, stack2, &operators, 2);
	else if (second < first && second < third && third < first)
		case1_3_5(stack1, stack2, &operators, 3);
	else if (first < second && third < second && first < third)
		case2_4(stack1, stack2, &operators, 4);
	else if (first < second && third < second && third < first)
		case1_3_5(stack1, stack2, &operators, 5);
	return (operators);
}

static void	case1_3_5(t_stack *stack1, t_stack *stack2, t_list **root, int num)
{
	t_list	*operator;

	(void)stack2;
	if (num == 1)
	{
		swap_one_stack(stack1);
		operator = ft_lstnew("sa");
	}
	else if (num == 3)
	{
		rotate_one_stack(stack1);
		operator = ft_lstnew("ra");
	}
	else if (num == 5)
	{
		rrotate_one_stack(stack1);
		operator = ft_lstnew("rra");
	}
	if (operator == NULL)
		exit(1);
	ft_lstadd_back(root, operator);
}

static void	case2_4(t_stack *stack1, t_stack *stack2, t_list **root, int num)
{
	t_list	*operator;

	(void)stack2;
	if (num == 2)
	{
		swap_one_stack(stack1);
		rrotate_one_stack(stack1);
		operator = ft_lstnew("sa");
		if (operator == NULL)
			exit(1);
		ft_lstadd_back(root, operator);
		operator = ft_lstnew("rra");
	}
	else if (num == 4)
	{
		swap_one_stack(stack1);
		rotate_one_stack(stack1);
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
