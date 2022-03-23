# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 22:37:29 by hmoon             #+#    #+#              #
#    Updated: 2022/03/23 17:27:38 by hmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= push_swap
NAME_BONUS		:= checker
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

SRCS_BONUS			:= $(addprefix ./srcs/, \
					checker.c \
					parse_argv.c \
					print_error.c \
					make_stack.c order_stack.c \
					util_stack.c)
OBJS_FILE_BONUS		:= $(SRCS_BONUS:.c=.o)

.PHONY	: all
all		: libft $(NAME) $(NAME_BONUS)

$(NAME)	: $(OBJS_FILE) $(INCLUDE_FILE)
		$(CC) $(CFLAGS) $(LIBFT_LIB) $(OBJS_FILE) -o $(NAME)

$(NAME_BONUS) : $(OBJS_FILE_BONUS) $(INCLUDE_FILE)
		$(CC) $(CFLAGS) $(LIBFT_LIB) $(OBJS_FILE_BONUS) -o $(NAME_BONUS)

%.o		: %.c
		$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_DIR) -c $< -o $@

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
