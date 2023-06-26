# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 13:58:16 by ligabrie          #+#    #+#              #
#    Updated: 2023/06/26 13:58:18 by ligabrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc -Wall -Wextra -Werror
CC_FLAGS = -Llibft -lft

%.o:%.c
	$(CC) -c -o $@ $^
	
all:	libft server client

libft: 
	make -C libft
	
server: server.c libft/libft.a
	$(CC) -o $@ $< $(CC_FLAGS)

client: client.c libft/libft.a
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a
	make -C libft fclean

re:	fclean all

.PHONY: libft clean fclean re
