# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 18:27:25 by tibarbos          #+#    #+#              #
#    Updated: 2024/08/02 19:56:55 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Compiler && Tools
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Output colors
RED= \e[31m
GREEN= \e[32m
BLUE= \e[34m
WHITE= \e[37m

# Source && Object Files
SRC = ./src/push_main.c ./src/bubble.c ./src/errors.c \
	./src/functions.c ./src/auxiliary.c \
	./src/small_rot.c ./src/big_rot.c ./src/functions_2.c \
	./src/big_2.c ./src/frees.c
OBJDIR= ./obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

.PHONY: all clean fclean re

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(BLUE)push_swap: $(GREEN)program compiled$(WHITE)"

all: $(NAME)

clean:
	@$(RM) $(OBJDIR)
	@echo "$(BLUE)push_swap: $(RED)object files removed$(WHITE)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)push_swap: $(RED)program and object files removed$(WHITE)"

re: fclean all
