# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 13:43:25 by ibettenc          #+#    #+#              #
#    Updated: 2025/11/03 14:12:31 by ibettenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ARGUMENTS

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

###################################################
## SOURCES

SRC = ft_isdigit.c ft_atoi.c ft_split.c \
       ft_printf.c ft_printf_utils.c

SRCB = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
	ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

###################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
##################################################
## POUR TESTER
#
#so:
#	$(CC) -fPIC $(CFLAGS) $(SRC) $(SRCB)
#	gcc -shared -o libft.so $(OBJ) $(OBJB)
#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(SRCB)
#	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJB)
##################################################
## BONUS

bonus: $(OBJ) $(OBJB)
	ar rcs $(NAME) $(OBJ) $(OBJB)

##################################################
## CLEAN

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
