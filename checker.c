
#include "includes/push_swap.h"

char *join(char *s1, char *s2)
{
    char *res;
    int i = 0;

    if (!s1)
        return (ft_strdup(s2));
    res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

int    execute(char *input, t_stack  *stack_a, t_stack   *stack_b)
{
    char **actions;
    int i;

    actions = ft_split(input, '\n');
    i = 0;
    while (actions[i] != NULL)
    {
        if (!ft_strncmp(actions[i], "sa", 3))
            swap(stack_a, 'x');
        else if (!ft_strncmp(actions[i], "sb", 3))
            swap(stack_b, 'x');
        else if (!ft_strncmp(actions[i], "ss", 3))
            swaps(stack_a, stack_b, 0);
        else if (!ft_strncmp(actions[i], "pa", 3))
            push(stack_b, stack_a, 'x');
        else if (!ft_strncmp(actions[i], "pb", 3))
            push(stack_a, stack_b, 'x');
        else if (!ft_strncmp(actions[i], "ra", 3))
            rotate(stack_a, 'x');
        else if (!ft_strncmp(actions[i], "rb", 3))
            rotate(stack_b, 'x');
        else if (!ft_strncmp(actions[i], "rr", 3))
            rrot(stack_a, stack_b, 0);
        else if (!ft_strncmp(actions[i], "rra", 3))
            rrotate(stack_a, 'x');
        else if (!ft_strncmp(actions[i], "rrb", 3))
            rrotate(stack_b, 'x');
        else if (!ft_strncmp(actions[i], "rrr", 3))
            rrrot(stack_a, stack_b, 0);
        else
            return (0);
        i++;
    }
    free_tabs(actions);
    return (1);
}

void    read_exec(t_stack *stack_a, t_stack *stack_b)
{
    int ret;
    char buff[2];
    char *actions;

    actions = NULL;
    while ((ret = read(0, buff, 1)) > 0)
    {
        buff[ret] = '\0';
        actions = join(actions, buff);
    }
    ret = 0;
    if (actions)
        ret = execute(actions, stack_a, stack_b);
    if (ret != 1)
        ft_putstr_fd("Errors\n", 2);
    else if (sorted(stack_a) && stack_b->head->next == NULL && ret == 1)
        ft_putstr_fd("OK\n", 1);
    // else if (sorted(stack_a))
    //     ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);
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
			ft_putstr_fd("Errors\n", 2);
		else
		{
            read_exec(stack_a, stack_b);
			free_stack(stack_a, stack_b);
		}
		free(stack_a);
		free(stack_b);
	}
	return (0);
}