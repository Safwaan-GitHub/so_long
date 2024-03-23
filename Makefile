# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanoor <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 06:56:37 by sanoor            #+#    #+#              #
#    Updated: 2024/03/23 14:32:54 by sanoor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libx
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CSOURCE = main.c map.c gnl/get_next_line.c \
	  gnl/get_next_line_utils.c error_handle.c
OSOURCE = $(CSOURCE:.c = .o)

$(NAME): $(OSOURCE)
	$(CC) $(OSOURCE) libmlx_Linux.a -Lminilibx-linux -Ignl -Iminilibx-linux -lXext -lX11 -lm -lz -g -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm $(NAME)	

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re
