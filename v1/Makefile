# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 18:27:25 by tibarbos          #+#    #+#              #
#    Updated: 2023/09/22 10:14:21 by tibarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIB = -lftprintf
SRC = push_main.c bubble.c errors.c functions.c auxiliary.c \
	small_rot.c big_rot.c functions_2.c big_2.c
OBJS = ${SRC:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L. $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#\
cc -o name source1.c source2.c ... sourceN.c -L. -lftprintf \
The linker automatically adds the necessary "lib" prefix and the file extension. \
include "ft_printf.h" no header \
ter ft_printf.h e libftprintf.a na directory \