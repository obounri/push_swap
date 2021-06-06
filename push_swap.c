/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unixpassword <unixpassword@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:57:57 by obounri           #+#    #+#             */
/*   Updated: 2021/06/05 20:15:57 by unixpasswor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	vizualize(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp_a = NULL; // test
	t_list	*tmp_b;

	printf("stack [a] :\n");
	// printf("pos min = [%d]\n", min(stack_a));
	tmp_a = stack_a->head->next;
	while (tmp_a)
	{
		printf("[%d] pos = [%d]\n", tmp_a->value, tmp_a->pos);
		tmp_a = tmp_a->next;
	}
	printf("len = %d\n\n", stack_a->len);

	printf("stack [b] :\n");
	tmp_b = stack_b->head->next;
	while (tmp_b)
	{
		printf("[%d] pos = [%d]\n", tmp_b->value, tmp_b->pos);
		tmp_b = tmp_b->next;
	}
	// printf("pos min = [%d]\n", min(stack_a));
	printf("len = %d\n\n****************\n\n", stack_b->len);
}

int		main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (ac >= 2)
	{
		stack_a = malloc(sizeof(t_stack));
		stack_b = malloc(sizeof(t_stack));
		stack_a = init_stacks(&av[1], stack_a, stack_b);
		if (!(stack_a))
			ft_putstr_fd("Error\n", 2);
		else
		{
			// vizualize(stack_a, stack_b);
			if (!sorted(stack_a))
			{
				sort(stack_a, stack_b);
				// vizualize(stack_a, stack_b);
			}
			free_stack(stack_a, stack_b);
		}
		free(stack_a);
		free(stack_b);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
