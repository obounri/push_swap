/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:43:41 by obounri           #+#    #+#             */
/*   Updated: 2021/06/08 17:21:45 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	int				value;
	int				pos;
}					t_list;

typedef struct s_stack
{
	t_list			*head;
	int				len;
	int				keys[7];
	int				chunks;
	int				err;
}					t_stack;

void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);

t_stack		*init_stacks(char **args, t_stack *stack_a, t_stack *stack_b);
void		free_tabs(char **tab);
void		free_stack(t_stack	*stack_a, t_stack	*stack_b);

int			new_element(t_stack *stack, char **new);
t_list		*list_last(t_list	*list, int b_last);
void		fix_pos(t_stack *stack_a, t_stack *stack_b);

int			swap(t_stack	*stack, char s);
void		swaps(t_stack	*stack_a, t_stack	*stack_b, int action);
int			push(t_stack *from, t_stack *to, char s);
int			rotate(t_stack	*stack, char s);
void		rrot(t_stack *stack_a, t_stack *stack_b, int action);
int			rrotate(t_stack	*stack, char s);
void		rrrot(t_stack *stack_a, t_stack *stack_b, int action);

int			sorted(t_stack	*stack);
void		sort(t_stack	*stack_a, t_stack	*stack_b);
int			min(t_stack	*stack);
void		sort_2(t_stack	*stack_a);
void		sort_3(t_stack	*stack_a);
void		sort_10(t_stack	*stack_a, t_stack	*stack_b);

void		partition(t_stack	*stack);

#endif