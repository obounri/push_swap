/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imannouc <imannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:07:25 by obounri           #+#    #+#             */
/*   Updated: 2021/06/04 07:52:11 by imannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_chunks(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		chunks;
	t_list	*list_a;

	i = 0;
	if (stack_a->len <= 100)
		chunks = 3;
	else
		chunks = 7;
	while (i < chunks)
	{
		list_a = stack_a->head->next;
		while (list_a)
		{
			if (list_a->value <= stack_a->keys[i])
			{
				if (list_a->pos < (stack_a->len / 2))
					while (list_a->pos != 0)
						rotate(stack_a, 'a');
				else
					while (list_a->pos != 0)
						rrotate(stack_a, 'a');
				push(stack_a, stack_b, 'b');
				list_a = stack_a->head->next;
			}
			else
				list_a = list_a->next;
		}
		i++;
	}
}

int	max(t_stack *stack)
{
	t_list	*list;
	int		tmp;
	int		pos;

	list = stack->head->next;
	tmp = list->value;
	pos = list->pos;
	list = list->next;
	while (list)
	{
		if (list->value > tmp)
		{
			tmp = list->value;
			pos = list->pos;
		}
		list = list->next;
	}
	return (pos);
}

void	sort_100(t_stack *stack_a, t_stack *stack_b)
{
	partition(stack_a);
	push_chunks(stack_a, stack_b);
	while (stack_a->len != 0)
	{
		if (min(stack_a) < (stack_a->len / 2))
			while (min(stack_a) != 0)
				rotate(stack_a, 'a');
		else
			while (min(stack_a) != 0)
				rrotate(stack_a, 'a');
		push(stack_a, stack_b, 'b');
	}
	while (stack_b->len != 0)
	{
		if (max(stack_b) < (stack_b->len / 2))
			while (max(stack_b) != 0)
				rotate(stack_b, 'b');
		else
			while (max(stack_b) != 0)
				rrotate(stack_b, 'b');
		push(stack_b, stack_a, 'a');
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 2)
		sort_2(stack_a);
	else if (stack_a->len == 3)
		sort_3(stack_a);
	else if (stack_a->len <= 10)
		sort_10(stack_a, stack_b);
	else if (stack_a->len <= 500)
		sort_100(stack_a, stack_b);
}
