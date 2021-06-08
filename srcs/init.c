/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:49:03 by obounri           #+#    #+#             */
/*   Updated: 2021/06/08 17:50:35 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_number(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = 0;
		if ((nums[i][j] == '-' || nums[i][j] == '+')
			&& (ft_strlen(nums[i]) == 1))
			return (0);
		else if (nums[i][j] == '-' || nums[i][j] == '+')
			j++;
		while (nums[i][j])
		{
			if (!ft_isdigit(nums[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	duplicate(t_stack *stack)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	list = stack->head->next;
	i = 0;
	if (!list)
		return (0);
	while (list->next)
	{
		tmp = stack->head;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (i == tmp->pos)
				continue ;
			else if (list->value == tmp->value)
				return (1);
		}
		list = list->next;
		i++;
	}
	return (0);
}

void	init_values(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->err = 0;
	stack_a->len = 0;
	stack_b->len = 0;
	stack_a->head = malloc(sizeof(t_list));
	stack_b->head = malloc(sizeof(t_list));
	stack_a->head->next = NULL;
	stack_b->head->next = NULL;
	stack_a->head->pos = -1;
	stack_b->head->pos = -1;
}

t_stack	*init_stacks(char **args, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	char	**actions;

	init_values(stack_a, stack_b);
	i = -1;
	while (args[++i])
	{
		actions = ft_split(args[i], ' ');
		if (!is_number(actions))
			stack_a->err = 1;
		free_tabs(actions);
	}
	i = -1;
	while (args[++i])
		if (!new_element(stack_a, ft_split(args[i], ' ')))
			stack_a->err = 1;
	if (duplicate(stack_a))
		stack_a->err = 1;
	return (stack_a);
}
