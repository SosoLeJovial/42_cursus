# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 11:39:56 by tsofien-          #+#    #+#              #
#    Updated: 2024/02/23 15:28:34 by tsofien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap.a

SRCS_DIR = src/operations src/utils src/stack src/tester src/sort

SRCS = $(foreach SRCS_DIR, $(SRCS_DIR), $(wildcard $(SRCS_DIR)/*.c))

OBJ_DIR = ./obj

OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c ./includes/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
	

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I./includes

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) push_swap.a


re: fclean all


	
.PHONY: all clean fclean re 