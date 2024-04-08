# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 20:58:45 by tsofien-          #+#    #+#              #
#    Updated: 2024/04/07 18:19:12 by tsofien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_DIR = src/utils src/parsing

SRCS = main.c $(foreach dir, $(SRCS_DIR), $(wildcard $(dir)/*.c))

OBJ_DIR = ./obj


OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_FLAGS = -L./libft -lft
MLX_FLAGS = -L./libmlx -lXext -lX11

RM = rm -f

LIBMLX = libmlx/libmlx.a
LIBFT = libft/libft.a

all: $(NAME) $(LIBMLX) $(LIBFT)

$(NAME): $(OBJS) $(INC)
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME) 

$(LIBMLX):
	make -C ./libmlx

$(LIBFT):
	make -C ./libft

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I./includes -I/libft -I/mlx -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	make -C ./libmlx clean
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libmlx fclean
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re