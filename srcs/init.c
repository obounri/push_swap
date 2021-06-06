/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unixpassword <unixpassword@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:49:03 by obounri           #+#    #+#             */
/*   Updated: 2021/06/05 21:06:38 by unixpasswor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tabs(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_stack(t_stack	*stack_a, t_stack	*stack_b)
{
	t_list	*list;
	t_list	*tmp;
	
	list = stack_a->head;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(stack_b->head);
}

int	is_number(char **nums)
{
	int		i;
	int		j;

	i = 0;
	while (nums[i])
	{
		j = 0;
		if ((nums[i][j] == '-' || nums[i][j] == '+') && (ft_strlen(nums[i]) == 1))
		{
			free_tabs(nums);
			return (0);
		}
		else if (nums[i][j] == '-' || nums[i][j] == '+')
			j++;
		while (nums[i][j])
		{
			if (!ft_isdigit(nums[i][j]))
			{
				free_tabs(nums);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_tabs(nums);
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

t_stack	*init_stacks(char **args, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = -1;
	while (args[++i])
		if (!is_number(ft_split(args[i], ' ')))
			return (NULL);
	stack_a->len = 0;
	stack_b->len = 0;
	stack_a->head = malloc(sizeof(t_list));
	stack_b->head = malloc(sizeof(t_list));
	stack_a->head->next = NULL;
	stack_b->head->next = NULL;
	stack_a->head->pos = -1;
	stack_b->head->pos = -1;
	i = -1;
	while (args[++i])
		if (!new_element(stack_a, ft_split(args[i], ' ')))
			return (NULL);
	if (duplicate(stack_a))
		return (NULL);
	return (stack_a);
}
