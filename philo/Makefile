# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 14:18:51 by mbarra            #+#    #+#              #
#    Updated: 2022/02/12 15:37:36 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		philo

HDR			=		$(wildcard $(HDR_DIR)/*.h)

HDR_DIR		=		./inc

SRC			=		$(wildcard $(SRC_DIR)/*.c)

SRC_DIR		=		./src

OBJ			=		$(patsubst %.c, %.o, $(SRC))

CC			=		gcc
RM			=		rm -f
CFLAGS		=		-pthread -Wall -Wextra -Werror #-O2

%.o: %.c $(HDR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@$(RM) $(SRC_DIR)/*.o


clean:
	@$(RM) $(OBJ)

f: clean
	@$(RM) $(NAME)

re: f all

.PHONY: all clean f re

# OBJ_LIST			=		$(addprefix $(OBJ_DIR)/, $(OBJ_LIST))
# rm -rf $(OBJ_DIR)
# @echo $(OBJ)
# $(OBJ_DIR):
# mkdir -p $(OBJ_DIR)
# OBJ_DIR		=		./obj