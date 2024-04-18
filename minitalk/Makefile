# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 16:26:38 by tsofien-          #+#    #+#              #
#    Updated: 2024/04/18 16:37:05 by tsofien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client/client.a
SERVER = server/server.a

SRCS = server/server.c
SRCC = client/client.c

OBJS = $(SRCS:.c=.o)
OBJC = $(SRCC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

all: $(CLIENT) $(SERVER)

$(SERVER): $(OBJS)
	ar rc $(SERVER) $(OBJS)
	ranlib $(SERVER)
	
$(CLIENT): $(OBJS)
	ar rc $(CLIENT) $(OBJC)
	ranlib $(CLIENT)

%.o: %.c ../minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $() client.a


re: fclean all

.PHONY: all clean fclean re