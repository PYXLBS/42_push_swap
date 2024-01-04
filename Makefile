# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 18:27:56 by pabertha          #+#    #+#              #
#    Updated: 2024/01/04 18:40:35 by pabertha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = algo.c \
	arg_to_lst.c \
	error.c \
	lstadd.c \
	lstclear.c \
	lstnew.c \
	lstsize.c \
	parsing.c \
	sprrr.c \
	utils_algo.c \
	utils.c \
	main.c \

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
		rm -f $(NAME) $(NAME_BONUS)

re : fclean all

everything : all clean
			norminette -R CheckForbiddenSourceHeader *.c

.PHONY : all clean fclean re everything
