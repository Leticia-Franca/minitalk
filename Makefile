# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 03:08:49 by lfranca-          #+#    #+#              #
#    Updated: 2021/11/24 13:41:11 by lfranca-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compilar libft
#daí vai acionar APENAS O SERVER? (e o client.c fica a cargo do próprio usuario?)
CLIENT = client
SERVER = server
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
LFT		=	libft/libft.a
INC		=	-I ./inc -I ./libft/
LIB		=	-L ./libft/ -lft
SRC_CLIENT		=	client.c 
SRC_SERVER		=	server.c 
OBJ_SERVER		=	$(SRC_SERVER:.c=.o)
OBJ_CLIENT		=	$(SRC_CLIENT:.c=.o)

all: $(LFT) $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(LIB) $< -o $@

$(SERVER): $(OBJ_SERVER)
	$(CC) $(FLAGS) $(LIB) $< -o $@

$(LFT): @make -s -C libft
	@echo "Libft compiled!"

clean:
	@make -s $@ -C libft
	@rm -rf $(OBJ_CLIENT)
	@rm -rf $(OBJ_SERVER)
	@echo "object files removed."

fclean:		clean
	@make -s $@ -C libft
	@rm -rf $(CLIENT) $(SERVER)
	@echo "binary files removed."

re:		fclean all

.PHONY:		all clean fclean re

