# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 16:26:38 by tsofien-          #+#    #+#              #
#    Updated: 2024/04/22 14:46:38 by tsofien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client/client
SERVER = server/server

SRCS = server/server.c
SRCC = client/client.c

OBJS = $(SRCS:.c=.o)
OBJC = $(SRCC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f
LIBFT = lib/libft/libft.a
LIBFT_FLAGS = -L lib/libft -lft

all: $(CLIENT) $(SERVER) $(LIBFT)

$(SERVER): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(SERVER)

$(CLIENT): $(OBJC) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJC) $(LIBFT_FLAGS) -o $(CLIENT)

$(LIBFT):
	make -C lib/libft

clean:
	$(RM) $(OBJS) $(OBJC)
	make -C lib/libft clean

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	make -C lib/libft fclean


re: fclean all

.PHONY: all clean fclean re