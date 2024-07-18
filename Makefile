# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 18:27:25 by tibarbos          #+#    #+#              #
#    Updated: 2024/07/18 17:48:46 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = ./src/push_main.c ./src/bubble.c ./src/errors.c \
	./src/functions.c ./src/auxiliary.c \
	./src/small_rot.c ./src/big_rot.c ./src/functions_2.c \
	./src/big_2.c ./src/frees.c
OBJS = ${SRC:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
