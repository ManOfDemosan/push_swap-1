# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 22:57:09 by hmoon             #+#    #+#              #
#    Updated: 2022/03/19 16:15:40 by hmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

SRCS_DIR	:= ./
SRCS_NAME	:= push_swap.c\
				push_swap_util.c stack.c\
				command.c solve.c\
				libft_util_1.c libft_util_2.c
SRCS		:= $(addprefix $(SRCS_DIR),$(SRCS_NAME))
OBJS		:= ${SRCS:.c=.o}

HEADER_DIR	:= ./
HEADER_FILE	:= push_swap.h
HEADER		:= $(addprefix $(HEADER_DIR),$(HEADER_FILE))
INCLUDE		:= -I$(HEADER)


$(NAME)	: $(OBJS)
		$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -g -o $(NAME)


%.o		: %.c $(HEADER)
		$(CC) $(CFLAGS) $(INCLUDE) -c -g $< -o $@

.PHONY	: all
all		: $(NAME)

.PHONY	: clean
clean	:
		$(RM) $(OBJS)

.PHONY	: fclean
fclean	: clean
		$(RM) $(NAME)

.PHONY	: re
re		: fclean all
