# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obounri <obounri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/04 16:03:37 by obounri           #+#    #+#              #
#    Updated: 2021/06/08 17:15:58 by obounri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = includes/push_swap.h

PROG1 = push_swap
PROG2 = checker

SRCS = srcs/init.c \
	srcs/lists.c \
	srcs/actions.c \
	srcs/sorting.c \
	srcs/sorting_utils.c \
	srcs/sorting_10.c

LIBFT_MAKEFILE_PATH = srcs/libft/ 
LIBFT = srcs/libft/libft.a
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

$(PROG1): $(SRCS) $(LIBFT) $(HEADER) push_swap.c
	$(CC) $(CFLAGS) push_swap.c $(SRCS) $(LIBFT) -o $(PROG1)

$(PROG2): $(SRCS) $(LIBFT) $(HEADER) checker.c
	$(CC) $(CFLAGS) checker.c $(SRCS) $(LIBFT) -o $(PROG2)
	
$(LIBFT): $(LIBFT_SRCS)
	make -C $(LIBFT_MAKEFILE_PATH)

clean:
	rm -f $(LIBFT_OBJS)

fclean: clean
	rm -f $(PROG1) $(PROG2) $(LIBFT)

re: fclean all