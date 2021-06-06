/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imannouc <imannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:30:36 by obounri           #+#    #+#             */
/*   Updated: 2021/06/04 07:14:59 by imannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min(t_stack *stack)
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
		if (list->value < tmp)
		{
			tmp = list->value;
			pos = list->pos;
		}
		list = list->next;
	}
	return (pos);
}

int	sorted(t_stack *stack)
{
	t_list	*list;
	int		tmp;

	list = stack->head->next;
	if (!list)
		return (1);
	tmp = list->value;
	list = list->next;
	while (list)
	{
		if (tmp > list->value)
			return (0);
		tmp = list->value;
		list = list->next;
	}
	return (1);
}

void	bubble_sort(t_stack *stack, int **tmp_stack)
{
	int		pass;
	int		i;
	int		len;
	int		tmp_swap;

	pass = 1;
	while (pass)
	{
		pass = 0;
		i = 0;
		len = stack->len;
		while (len--)
		{
			if ((*tmp_stack)[i] > (*tmp_stack)[i + 1] && len != 0)
			{
				tmp_swap = (*tmp_stack)[i];
				(*tmp_stack)[i] = (*tmp_stack)[i + 1];
				(*tmp_stack)[i + 1] = tmp_swap;
				pass = 1;
			}
			i++;
		}
	}
}

void	get_keys(t_stack *stack, int *tmp)
{
	if (stack->len <= 100)
	{
		stack->keys[0] = tmp[stack->len / 4];
		stack->keys[1] = tmp[stack->len / 2];
		stack->keys[2] = tmp[(stack->len / 4) *3];
	}
	else
	{
		stack->keys[0] = tmp[stack->len / 8];
		stack->keys[1] = tmp[stack->len / 4];
		stack->keys[2] = tmp[(stack->len / 8) *3];
		stack->keys[3] = tmp[stack->len / 2];
		stack->keys[4] = tmp[(stack->len / 8) *5];
		stack->keys[5] = tmp[(stack->len / 4) *3];
		stack->keys[6] = tmp[(stack->len / 8) *7];
	}
}

void	partition(t_stack *stack)
{
	int		*tmp_stack;
	int		i;
	t_list	*list;

	list = stack->head->next;
	tmp_stack = malloc(sizeof(int) * stack->len);
	i = 0;
	while (list)
	{
		tmp_stack[i] = list->value;
		i++;
		list = list->next;
	}
	bubble_sort(stack, &tmp_stack);
	get_keys(stack, tmp_stack);
	free(tmp_stack);
}
