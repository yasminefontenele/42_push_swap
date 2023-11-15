# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 14:55:14 by yfontene          #+#    #+#              #
#    Updated: 2023/04/26 14:55:14 by yfontene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
GREEN	=	\033[0;32m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
END		=	\033[0m

HEADER	=	libft.h
NAME 	= 	libft.a

#Directories, compiler and flags
INC 	= 	inc/
SRC_DIR = 	src/
OBJ_DIR = 	obj/
CC 		= 	gcc
CFLAGS	=	-Wall -Wextra -Werror -I
RM 		=	rm -rf
AR 		= 	ar rcs

LIBFT	= 	$(SRC_DIR)ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	  		$(SRC_DIR)ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
	 		$(SRC_DIR)ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
			$(SRC_DIR)ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
	 		$(SRC_DIR)ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
	  		$(SRC_DIR)ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
	  		$(SRC_DIR)ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
			$(SRC_DIR)ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			$(SRC_DIR)ft_lstdelone.c ft_lstclear.c ft_putstr_fd.c\
			$(SRC_DIR)ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c\
			$(SRC_DIR)ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			$(SRC_DIR)ft_lstadd_back.c ft_lstiter.c ft_lstmap.c\

PRINTF 	= 	$(SRC_DIR)ft_printf_base.c ft_printf_hexp.c\
			$(SRC_DIR)ft_printf_type.c ft_printf.c\

GNL 	= 	$(SRC_DIR)get_next_line_utils.c get_next_line.c\

# Concatenate all source files
SRC		= 	$(LIBFT) $(PRINTF) $(GNL)

#Por exemplo, se $(SRC) contiver src/ft_isalpha.c src/ft_strlen.c, a linha OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC)) resultará em obj/ft_isalpha.o obj/ft_strlen.o.
OBJ 	= 	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

OBJ		= 	$(SRC:.c=.o)
OBJ_B	= 	$(BONUS:.c=.o)

all:		$(NAME)

$(NAME): 		$(OBJ)
				@echo "$(YELLOW)Compiling Libft...$(END)"
				@$(AR) $(NAME) $(OBJ)
				@echo "$(GREEN)Libft succesfully compiled!$(END)"

#VER A LINHA 89 DO DELA
						
clean: 		
				@rm -rf $(OBJ)
				@$(RM) .cache_exists
				@echo "$(RED)Libft objects deleted!$(END)"

fclean: 		clean
				@$(RM) $(NAME)
				@echo "$(RED)Libft deleted!$(END)"

re:				fclean	all

author: 
				@echo "$(GREEN)'yfontene'$(END)"

.PHONY:			all clean fclean re
