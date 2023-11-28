# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 17:21:14 by yfontene          #+#    #+#              #
#    Updated: 2023/11/28 18:53:48 by yfontene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN				=	\033[0;32m
RED					=	\033[0;31m
YELLOW				=	\033[0;33m
END					=	\033[0m

NAME 				= 	push_swap
HEADER				=	inc/push_swap.h

LIBFT				=	libft/libft.a
INC					=	inc/
COMMANDS_DIR		=	src/commands
PUSH_SWAP_DIR		=	src/push_swap
CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra -g
RM					=	rm -f
AR 					= 	ar rcs
OBJ_DIR 			= 	obj/

COMMANDS 			=	$(addprefix $(COMMANDS_DIR)/, $(wildcard *.c))
PUSH_SWAP 			=	$(addprefix $(PUSH_SWAP_DIR)/, $(wildcard *.c))
LIBFT_SRC   		=	$(wildcard libft/*.c)

SRC 				=	$(COMMANDS) $(PUSH_SWAP) $(LIBFT_SRC)
OBJ 				=	$(SRC:%.c=$(OBJ_DIR)%.o)

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(LIBFT) $(OBJ)
					@echo "$(YELLOW)Compiling push_swap...$(END)"
					@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
					@echo "$(GREEN)Push_swap succesfully compiled!$(END)"

$(OBJ_DIR)%.o:		$(SRC) $(HEADER)/%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

$(LIBFT):
					@make -C ./libft

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft
					@echo "$(RED)Push_swap objects deleted!$(END)"

fclean:				clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@echo "$(RED)Push_swap deleted!$(END)"
					
re:					fclean all

.PHONY:				all clean fclean re