# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 18:54:40 by tsofien-          #+#    #+#              #
#    Updated: 2024/01/28 05:46:10 by tsofien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) Makefile
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c ft_printf.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@
	

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) libftprintf.a


re: fclean all

.PHONY: all clean fclean re

