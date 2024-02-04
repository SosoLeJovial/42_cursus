# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 11:39:56 by tsofien-          #+#    #+#              #
#    Updated: 2024/02/04 08:38:50 by tsofien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap.a

SRCS = push_swap.c push_swap_utils.c push_swap_sort.c push_swap_sort_utils.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
	

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) libftprintf.a


re: fclean all

.PHONY: all clean fclean re