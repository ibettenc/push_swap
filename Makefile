# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 12:54:43 by ibettenc          #+#    #+#              #
#    Updated: 2025/11/03 14:48:53 by ibettenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
## ARGUMENTS

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

LIBFT = libft/libft.a


###################################################
## SOURCES

SRC = main.c verification.c manage_node.c operations/swap.c \
	operations/rotate.c operations/reverse_rotate.c operations/push.c \
	analyse_and_tools.c mini_sort.c big_sort.c treating_arguments.c \
	find_functions.c

OBJ = $(SRC:.c=.o)

###################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

##################################################
## CLEAN

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all  clean fclean re