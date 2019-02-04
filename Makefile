# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kykim <kykim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 16:36:07 by kykim             #+#    #+#              #
#    Updated: 2018/05/31 08:48:47 by kykim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFILES = main.c\
		 readandvalidcheck.c\
		 parsing.c\
		 board.c\
		 placetetrimino.c\
		 solve.c\
		 numoftet.c\
		 split.c\
		 freeboard.c\

OBJ = $(CFILES:.c=.o)

LIBFT = libft -lft

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		make -C $(LIBFT)
		gcc $(CGFLAGS) -c $(CFILES) -I.
		gcc $(OBJ) -L $(LIBFT) -o $(NAME)

clean:
		make -C libft/ clean
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		make -C libft/ fclean

re: fclean all

.PHONY: re all fclean clean
