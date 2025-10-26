# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 19:36:14 by ibettenc          #+#    #+#              #
#    Updated: 2025/10/26 13:51:38 by ibettenc         ###   ########.fr        #
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

SRC = main.c verification.c to_delete.c manage_node.c operations/swap.c \
	operations/rotate.c operations/reverse_rotate.c operations/push.c \
	analyse_and_tools.c sort_2_or_3.c big_sort.c

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