# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 22:37:29 by hmoon             #+#    #+#              #
#    Updated: 2022/03/23 16:50:18 by hmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= push_swap
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
RM				:= rm -f

LIBFT_DIR		:= ./libft
LIBFT_LIB		:= ./libft/libft.a

INCLUDE			:= ./include/
INCLUDE_FILE	:= $(addprefix $(INCLUDE), push_swap.h)

SRCS			:= $(addprefix ./srcs/, \
					push_swap.c parse_argv.c \
					print_error.c \
					make_stack.c order_stack.c \
					util_stack.c solve.c \
					solve_small.c)
OBJS_FILE		:= $(SRCS:.c=.o)

.PHONY	: all
all		: libft $(NAME)

$(NAME)	: $(OBJS_FILE) $(INCLUDE_FILE)
		$(CC) $(CFLAGS) $(LIBFT_LIB) $(OBJS_FILE) -g -o $(NAME)

%.o		: %.c
		$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_DIR) -c -g $< -o $@

.PHONY	: libft
libft	:
		@make -C ./libft all

.PHONY	: clean
clean	:
		@make -C ./libft clean
		@$(RM) $(OBJS_FILE)

.PHONY	: fclean
fclean	: clean
		@make -C ./libft fclean
		@$(RM) $(NAME)

.PHONY	: re
re		: fclean all
