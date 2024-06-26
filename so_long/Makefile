# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 20:58:45 by tsofien-          #+#    #+#              #
#    Updated: 2024/04/17 13:57:19 by tsofien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_DIR = src/utils src/parsing src/mlx_stuff src/gaming

SRCS = main.c $(foreach dir, $(SRCS_DIR), $(wildcard $(dir)/*.c))

OBJ_DIR = ./obj

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 
LIBFT_FLAGS = -L./libft -lft
MLX_FLAGS = -L./minilib -lmlx -lXext -lX11

RM = rm -f

LIBMLX = minilib/libmlx.a
LIBFT = libft/libft.a

all: $(NAME) $(LIBMLX) $(LIBFT)

$(NAME): $(OBJS) $(LIBMLX) $(LIBFT)
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(LIBMLX):
	make -C ./minilib

$(LIBFT):
	make -C ./libft

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	make -C ./minilib clean
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./minilib clean
	make -C ./libft fclean

re: fclean all 

.PHONY: all clean fclean re