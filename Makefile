# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obounri <obounri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/04 16:03:37 by obounri           #+#    #+#              #
#    Updated: 2021/06/07 20:24:33 by obounri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = includes/push_swap.h

PROG1 = push_swap
PROG2 = checker

PUSHS_SRCS = srcs/init.c \
	srcs/lists.c \
	srcs/actions.c \
	srcs/sorting.c \
	srcs/sorting_utils.c \
	srcs/sorting_10.c
CHECKER_SRCS = checker.c

LIBFT = libft.a
LIBFT_SRCS = srcs/libft/ft_isdigit.c \
	srcs/libft/ft_split.c \
	srcs/libft/ft_putstr_fd.c \
	srcs/libft/ft_atoi.c \
	srcs/libft/ft_putchar_fd.c \
	srcs/libft/ft_strlen.c \
	srcs/libft/ft_strncmp.c \
	srcs/libft/ft_strdup.c

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: $(PROG1) $(PROG2)

$(PROG1): $(PUSHS_SRCS) $(LIBFT) $(HEADER) push_swap.c
	$(CC) $(CFLAGS) push_swap.c $(PUSHS_SRCS) $(LIBFT) -o $(PROG1)

$(PROG2): $(CHECKER_SRCS) $(LIBFT) $(HEADER) checker.c
	$(CC) $(CFLAGS) checker.c $(PUSHS_SRCS) $(LIBFT) -o $(PROG2)
	
$(LIBFT): $(LIBFT_OBJS)
	ar rcs $(LIBFT) $(LIBFT_OBJS)

clean:
	rm -f $(LIBFT_OBJS)

fclean: clean
	rm -f $(PROG1) $(PROG2) $(LIBFT)

re: fclean all