# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 14:18:51 by mbarra            #+#    #+#              #
#    Updated: 2022/03/02 20:06:24 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		philo_bonus

HDR			=		$(wildcard $(HDR_DIR)/*.h)

HDR_DIR		=		./inc

SRC			=		$(wildcard $(SRC_DIR)/*.c)

SRC_DIR		=		./src

OBJ			=		$(patsubst %.c, %.o, $(SRC))

CC			=		gcc
RM			=		rm -f
CFLAGS		=		-pthread -Wall -Wextra -Werror -O2

%.o: %.c $(HDR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re