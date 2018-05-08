#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 12:56:23 by vdubinki          #+#    #+#              #
#    Updated: 2017/10/02 12:56:24 by vdubinki         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = hotrace

SRC = 	hashtable.c \
		func.c \
		get_next_line.c \
		gnl_func.c \
		main.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): *.h

.c.o:
	gcc $(FLAGS) -c $<

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
