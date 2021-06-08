/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:11:57 by obounri           #+#    #+#             */
/*   Updated: 2021/06/07 20:44:42 by obounri          ###   ########.fr       */
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

// void	vizualize(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_list	*tmp_a = NULL; // test
// 	t_list	*tmp_b;

// 	printf("stack [a] :\n");
// 	// printf("pos min = [%d]\n", min(stack_a));
// 	tmp_a = stack_a->head->next;
// 	while (tmp_a)
// 	{
// 		printf("[%d] pos = [%d]\n", tmp_a->value, tmp_a->pos);
// 		tmp_a = tmp_a->next;
// 	}
// 	printf("len = %d\n\n", stack_a->len);

// 	printf("stack [b] :\n");
// 	tmp_b = stack_b->head->next;
// 	while (tmp_b)
// 	{
// 		printf("[%d] pos = [%d]\n", tmp_b->value, tmp_b->pos);
// 		tmp_b = tmp_b->next;
// 	}
// 	// printf("pos min = [%d]\n", min(stack_a));
// 	printf("len = %d\n\n****************\n\n", stack_b->len);
// }
