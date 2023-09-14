# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tibarbos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 16:57:08 by tibarbos          #+#    #+#              #
#    Updated: 2023/05/15 12:25:57 by tibarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf
SRC = ft_printf.c ft_utils_1.c ft_utils_2.c ft_specs_1.c ft_specs_2.c \
      ft_hex.c
OBJS = ${SRC:.c=.o}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

#bonus:

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
