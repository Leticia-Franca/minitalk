# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 03:08:49 by lfranca-          #+#    #+#              #
#    Updated: 2021/11/24 14:27:33 by lfranca-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CLIENT = client
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
LFT		=	./libft/libft.a
INC		=	-I ./inc -I ./libft
LIB		=	-L ./libft/ -lft
SRC_CLIENT		=	client.c 
SRC_SERVER		=	server.c 
OBJ_SERVER		=	$(SRC_SERVER:.c=.o)
OBJ_CLIENT		=	$(SRC_CLIENT:.c=.o)

all: $(LFT) $(NAME) $(CLIENT)

$(NAME):	$(OBJ_SERVER) $(LFT)
	$(CC) $(FLAGS) $(INC) $(LIB) $^ -o $@

$(CLIENT):	$(OBJ_CLIENT) $(LFT)
	$(CC) $(FLAGS) $(INC) $(LIB) $^ -o $@

$(LFT):
	@make -s -C libft
	@echo "Libft compiled!"


clean:
	@make -s $@ -C libft
	@rm -rf $(OBJ_CLIENT)
	@rm -rf $(OBJ_SERVER)
	@echo "object files removed."

fclean:		clean
	@make -s $@ -C libft
	@rm -rf $(CLIENT) $(NAME)
	@echo "binary files removed."

re:		fclean all

.PHONY:		all clean fclean re

