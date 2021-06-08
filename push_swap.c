/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:57:57 by obounri           #+#    #+#             */
/*   Updated: 2021/06/08 17:51:42 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
			if (!sorted(stack_a))
				sort(stack_a, stack_b);
			free_stack(stack_a, stack_b);
		}
		if (stack_a->err == 1)
			free_stack(stack_a, stack_b);
		free(stack_a);
		free(stack_b);
	}
	return (0);
}
