/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:53:39 by obounri           #+#    #+#             */
/*   Updated: 2021/06/08 17:54:14 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*list_last(t_list *list, int b_last)
{
	t_list	*tmp;

	while (list->next)
	{
		tmp = list;
		list = list->next;
	}
	if (b_last == 1)
		return (tmp);
	return (list);
}

int	new_element(t_stack *stack, char **new)
{
	t_list		*new_list;
	t_list		*last;
	int			i;

	i = 0;
	while (new[i])
	{
		last = list_last(stack->head, 0);
		if (ft_atoi(new[i]) > INT_MAX || ft_atoi(new[i]) < INT_MIN)
		{
			free_tabs(new);
			return (0);
		}
		new_list = malloc(sizeof(t_list));
		new_list->value = (int)ft_atoi(new[i]);
		new_list->pos = last->pos + 1;
		new_list->next = NULL;
		last->next = new_list;
		stack->len++;
		i++;
	}
	free_tabs(new);
	return (1);
}

void	fix_pos(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (stack_a)
		a = stack_a->head->next;
	if (stack_b)
		b = stack_b->head->next;
	i = 0;
	while (a)
	{
		a->pos = i;
		i++;
		a = a->next;
	}
	i = 0;
	while (b)
	{
		b->pos = i;
		i++;
		b = b->next;
	}
}

int	rrotate(t_stack *stack, char s)
{
	t_list	*first;
	t_list	*b_last;
	t_list	*last;

	first = stack->head->next;
	if (!first || !first->next)
		return (0);
	last = list_last(stack->head, 0);
	b_last = list_last(stack->head, 1);
	stack->head->next = last;
	last->next = first;
	b_last->next = NULL;
	fix_pos(stack, NULL);
	if (s == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (s == 'b')
		ft_putstr_fd("rrb\n", 1);
	return (1);
}

void	rrrot(t_stack *stack_a, t_stack *stack_b, int action)
{
	int	ret1;
	int	ret2;

	ret1 = rrotate(stack_a, 'x');
	ret2 = rrotate(stack_b, 'x');
	if ((ret1 || ret2) && action == 1)
		ft_putstr_fd("rrr\n", 1);
}
