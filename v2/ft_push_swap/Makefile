# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 17:52:24 by jacher            #+#    #+#              #
#    Updated: 2021/05/06 16:11:12 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c \
push_swap_simple.c \
push_swap_complex.c \
checker_test.c \
../srcs/check_args.c \
../srcs/check_args_single.c \
../srcs/check_args_several.c \
../srcs/check_order.c \
../srcs/error_mngt.c \
../srcs/instructions.c \
../srcs/instructions_push.c \
../srcs/instructions_rotate.c \
../srcs/instructions_rrotate.c \
../srcs/instructions_swap.c \
../srcs/print_help.c

OBJS = ${SRCS:.c=.o}

CC = clang

CCFLAGS = -Wall -Werror -Wextra

NAME = push_swap

LIBFT = ../libft/libft.a

.c.o: ${LIBFT}
	${CC} ${CCFLAGS} -I ../libft/ -c $< -o${<:.c=.o}

${NAME}: ${LIBFT} ${OBJS} ../sort.h 
	${CC} ${CCFLAGS} -L ../libft ${OBJS} -o ${NAME} -lft

${LIBFT}:
	make bonus -C ../libft/

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
