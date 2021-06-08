/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:13:11 by obounri           #+#    #+#             */
/*   Updated: 2021/06/08 17:51:15 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

char	*join(char *s1, char *s2)
{
	char	*res;
	int		i;

	if (!s1)
		return (ft_strdup(s2));
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	while (*s1)
	{
		res[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		res[i] = *s2;
		i++;
		s2++;
	}
	res[i] = '\0';
	return (res);
}

int	exec_action(char **actions, int i, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(actions[i], "sa", ft_strlen(actions[i])))
		swap(stack_a, 'x');
	else if (!ft_strncmp(actions[i], "sb", ft_strlen(actions[i])))
		swap(stack_b, 'x');
	else if (!ft_strncmp(actions[i], "ss", ft_strlen(actions[i])))
		swaps(stack_a, stack_b, 0);
	else if (!ft_strncmp(actions[i], "pa", ft_strlen(actions[i])))
		push(stack_b, stack_a, 'x');
	else if (!ft_strncmp(actions[i], "pb", ft_strlen(actions[i])))
		push(stack_a, stack_b, 'x');
	else if (!ft_strncmp(actions[i], "ra", ft_strlen(actions[i])))
		rotate(stack_a, 'x');
	else if (!ft_strncmp(actions[i], "rb", ft_strlen(actions[i])))
		rotate(stack_b, 'x');
	else if (!ft_strncmp(actions[i], "rr", ft_strlen(actions[i])))
		rrot(stack_a, stack_b, 0);
	else if (!ft_strncmp(actions[i], "rra", ft_strlen(actions[i])))
		rrotate(stack_a, 'x');
	else if (!ft_strncmp(actions[i], "rrb", ft_strlen(actions[i])))
		rrotate(stack_b, 'x');
	else if (!ft_strncmp(actions[i], "rrr", ft_strlen(actions[i])))
		rrrot(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

int	execute(char *input, t_stack *stack_a, t_stack *stack_b)
{
	char	**actions;
	int		i;

	actions = ft_split(input, '\n');
	i = 0;
	while (actions[i] != NULL)
	{
		if (exec_action(actions, i, stack_a, stack_b) == 0)
			return (0);
		i++;
	}
	free_tabs(actions);
	return (1);
}

void	read_exec(t_stack *stack_a, t_stack *stack_b)
{
	int		ret;
	char	buff[2];
	char	*actions;

	actions = NULL;
	ret = read(0, buff, 1);
	while (ret > 0)
	{
		buff[ret] = '\0';
		actions = join(actions, buff);
		ret = read(0, buff, 1);
	}
	if (actions)
		ret = execute(actions, stack_a, stack_b);
	if (actions && ret != 1)
		ft_putstr_fd("Error\n", 2);
	else if (actions && sorted(stack_a)
		&& stack_b->head->next == NULL && ret == 1)
		ft_putstr_fd("OK\n", 1);
	else if (sorted(stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac >= 2)
	{
		stack_a = malloc(sizeof(t_stack));
		stack_b = malloc(sizeof(t_stack));
		stack_a = init_stacks(&av[1], stack_a, stack_b);
		if (stack_a->err == 1)
			ft_putstr_fd("Error\n", 2);
		else
		{
			read_exec(stack_a, stack_b);
			free_stack(stack_a, stack_b);
		}
		if (stack_a->err == 1)
			free_stack(stack_a, stack_b);
		free(stack_a);
		free(stack_b);
	}
	return (0);
}
