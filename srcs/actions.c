/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unixpassword <unixpassword@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:11:57 by obounri           #+#    #+#             */
/*   Updated: 2021/06/05 21:24:36 by unixpasswor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_stack *stack, char s)
{
	t_list	*list;
	t_list	*first;
	t_list	*second;
	t_list	*third;

	list = stack->head->next;
	if (!list || !list->next)
		return (0);
	first = list;
	second = first->next;
	third = second->next;
	stack->head->next = second;
	second->next = first;
	first->next = third;
	fix_pos(stack, NULL);
	if (s == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (s == 'b')
		ft_putstr_fd("sb\n", 1);
	return (1);
}

void	swaps(t_stack *stack_a, t_stack *stack_b, int action)
{
	int	ret1;
	int	ret2;

	ret1 = swap(stack_a, 'x');
	ret2 = swap(stack_b, 'x');
	if ((ret1 || ret2) && action == 1)
		ft_putstr_fd("ss\n", 1);
}

int	push(t_stack *from, t_stack *to, char s)
{
	t_list	*from_first;
	t_list	*to_first;
	t_list	*from_second;

	from_first = from->head->next;
	if (!from_first)
		return (0);
	from_first = from->head->next;
	from_second = from_first->next;
	to_first = to->head->next;
	from->head->next = from_second;
	to->head->next = from_first;
	from_first->next = to_first;
	fix_pos(from, to);
	from->len -= 1;
	to->len += 1;
	if (s == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (s == 'b')
		ft_putstr_fd("pb\n", 1);
	return (1);
}

int	rotate(t_stack *stack, char s)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->head->next;
	if (!first || !first->next)
		return (0);
	second = first->next;
	last = list_last(stack->head, 0);
	stack->head->next = second;
	last->next = first;
	first->next = NULL;
	fix_pos(stack, NULL);
	if (s == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (s == 'b')
		ft_putstr_fd("rb\n", 1);
	return (1);
}

void	rrot(t_stack *stack_a, t_stack *stack_b, int action)
{
	int	ret1;
	int	ret2;

	ret1 = rotate(stack_a, 'x');
	ret2 = rotate(stack_b, 'x');
	if ((ret1 || ret2) && action == 1)
		ft_putstr_fd("rr\n", 1);
}
