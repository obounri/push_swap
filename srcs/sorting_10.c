/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unixpassword <unixpassword@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:46:04 by obounri           #+#    #+#             */
/*   Updated: 2021/06/05 20:31:49 by unixpasswor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_stack *stack_a)
{
	t_list	*first;
	t_list	*second;

	first = stack_a->head->next;
	second = first->next;
	if (first->value > second->value)
		swap(stack_a, 'a');
}

void	sort_3(t_stack *stack_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = stack_a->head->next;
	second = first->next;
	third = second->next;
	if ((first->value > second->value) && (first->value < third->value))
		swap(stack_a, 'a');
	else if ((first->value > second->value) && (second->value > third->value))
	{
		swap(stack_a, 'a');
		rrotate(stack_a, 'a');
	}
	else if ((first->value > second->value) && (second->value < third->value))
		rotate(stack_a, 'a');
	else if ((first->value < second->value) && (first->value < third->value))
	{
		rrotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
	else if ((first->value < second->value) && (first->value > third->value))
		rrotate(stack_a, 'a');
}

void	sort_10(t_stack *stack_a, t_stack *stack_b)
{
	int	counter;

	counter = 0;
	while (stack_a->len > 3)
	{
		if (min(stack_a) < (stack_a->len / 2))
			while (min(stack_a) != 0)
				rotate(stack_a, 'a');
		else
			while (min(stack_a) != 0)
				rrotate(stack_a, 'a');
		push(stack_a, stack_b, 'b');
		counter++;
	}
	if (!sorted(stack_a))
		sort_3(stack_a);
	while (push(stack_b, stack_a, 'a') && (--counter));
}
