# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 20:58:45 by tsofien-          #+#    #+#              #
#    Updated: 2024/04/17 15:41:29 by tsofien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_DIR = src/render src/config src/parsing src/utils 

SRCS = main.c $(foreach dir, $(SRCS_DIR), $(wildcard $(dir)/*.c))

OBJ_DIR = ./obj

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 
LIBFT_FLAGS = -L./lib/libft -lft
MLX_FLAGS = -L./lib/minilibx-linux -lmlx -lXext -lX11

RM = rm -f

LIBMLX = lib/minilibx-linux/libmlx.a
LIBFT = lib/libft/libft.a

all: $(NAME) $(LIBMLX) $(LIBFT)

$(NAME): $(OBJS) $(LIBMLX) $(LIBFT)
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(LIBMLX):
	make -C ./lib/minilibx-linux

$(LIBFT):
	make -C ./lib/libft

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	make -C ./lib/minilibx-linux clean
	make -C ./lib/libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./lib/minilibx-linux clean
	make -C ./lib/libft fclean

re: fclean all 

.PHONY: all clean fclean re