# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 20:58:45 by tsofien-          #+#    #+#              #
#    Updated: 2024/04/06 14:47:49 by tsofien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_DIR = src/utils src/parsing

SRCS = main.c $(foreach dir, $(SRCS_DIR), $(wildcard $(dir)/*.c))

OBJ_DIR = ./obj

LIB = -L./libmlx 

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

MLX_FLAGS = -L./libmlx -lmlx -lXext -lX11

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	$(CC) $(OBJS) -o $(NAME) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

$(INC) : $(LIB)
	make -C ./libmlx $(MLX_FLAGS) -lm
clean:
	$(RM) -r $(OBJ_DIR)
	make -C ./libmlx clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libmlx fclean

re: fclean all

.PHONY: all clean fclean re