# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obounri <obounri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 13:10:19 by obounri           #+#    #+#              #
#    Updated: 2021/06/08 17:15:33 by obounri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
HEADER = libft.h
FCTS = ft_atoi.c \
ft_isdigit.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strdup.c \
ft_strlen.c \
ft_strncmp.c
OBJS = $(FCTS:.c=.o)
BONUS_OBJS = $(BONUS_FCTS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(FCTS)
	gcc $(FLAGS) -I $(HEADER) -c $(FCTS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
