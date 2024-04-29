# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 20:10:49 by tsofien-          #+#    #+#              #
#    Updated: 2024/04/29 20:27:43 by tsofien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putstr_fd.c \
ft_strchr.c ft_calloc.c ft_strdup.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_tolower.c ft_toupper.c ft_putendl_fd.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_split.c \
ft_putnbr_fd.c ft_striteri.c ft_putchar_fd.c \
gnl.c gnl_utils.c ft_realloc.c\

SRCSB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c  ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c  ft_lstmap_bonus.c \

FT_PRINTF = printf/libftprintf.a
FT_PRINTF_FLAGS = -L./printf -lftprintf

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME) $(FT_PRINTF)

$(NAME): $(OBJS) $(FT_PRINTF)
	ar rc $(NAME) $(OBJS) printf/*.o
	ranlib $(NAME)

$(FT_PRINTF):
	make -C printf

bonus: $(OBJSB)
	ar rc $(NAME) $(OBJSB)
	ranlib $(NAME)

%.o: %.c libft.h printf/libftprintf.h
	$(CC) $(CFLAGS) $(FT_PRINTF_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJSB)
	make -C printf clean

fclean: clean
	$(RM) $(NAME)
	make -C printf fclean

re: fclean all

.PHONY: all clean fclean re
