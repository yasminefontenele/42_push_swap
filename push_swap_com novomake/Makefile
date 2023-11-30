# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 20:09:43 by yfontene          #+#    #+#              #
#    Updated: 2023/11/29 20:09:43 by yfontene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = inc/push_swap.h
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

COMMANDS_DIR = src/commands
PUSH_SWAP_DIR = src/push_swap

COMMANDS_FILES = $(addprefix $(COMMANDS_DIR)/, \
	swap.c \
	push.c \
	rotate.c \
	rev_rotate.c \
	sort_stacks.c \
	sort_three.c \
)

PUSH_SWAP_FILES = $(addprefix $(PUSH_SWAP_DIR)/, \
	push_swap.c \
	handle_error.c \
	init_a_to_b.c \
	init_b_to_a.c \
	split.c \
	stack_init.c \
	stack_utils.c \
)

SRC = $(COMMANDS_FILES) $(PUSH_SWAP_FILES)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): force
	$(MAKE) -C libft

force: 
	@true

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re force