# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 20:58:45 by tsofien-          #+#    #+#              #
#    Updated: 2024/03/27 21:19:13 by tsofien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_DIR = src/utils src/parsing

SRCS = main.c $(foreach dir, $(SRCS_DIR), $(wildcard $(dir)/*.c))

OBJ_DIR = ./obj

LIB = -L./libmlx -lmlx -lXext -lX11 -lm

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LIB) $(OBJS) -o $(NAME) 
	make -C ./libmlx

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	make -C ./libmlx clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libmlx fclean

re: fclean all

.PHONY: all clean fclean re