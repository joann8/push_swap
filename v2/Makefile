# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 17:52:24 by jacher            #+#    #+#              #
#    Updated: 2021/05/13 23:38:00 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_S = srcs/check_args.c \
		srcs/check_args_single.c \
		srcs/check_args_several.c \
		srcs/check_order.c \
		srcs/error_mngt.c \
		srcs/instructions.c \
		srcs/instructions_update.c \
		srcs/instructions_bis.c \
		srcs/instructions_push.c \
		srcs/instructions_rotate.c \
		srcs/instructions_rrotate.c \
		srcs/instructions_swap.c \
		srcs/print_help.c \
		srcs/utils.c

SRCS_C = srcs/checker.c ${SRCS_S}
SRCS_P = ${SRCS_S} \
		srcs/push_swap.c \
		srcs/push_swap_complex.c \
		srcs/push_swap_complex_bis.c \
		srcs/push_swap_complex_special.c \
		srcs/push_swap_complex_special_bis.c \
		srcs/push_swap_complex_3_a.c \
		srcs/push_swap_complex_3_b.c \
		srcs/push_swap_complex_4_a.c \
		srcs/push_swap_complex_4_b.c \
		srcs/push_swap_simple.c 

OBJS_C = ${SRCS_C:.c=.o}
OBJS_P = ${SRCS_P:.c=.o}

CC = clang

CCFLAGS = -Wall -Werror -Wextra

NAME_C = checker
NAME_P = push_swap

LIBFT = ./libft/libft.a

.c.o: ${LIBFT}
	${CC} ${CCFLAGS} -I ./libft/ -c $< -o${<:.c=.o}

${NAME_P}: ${LIBFT} ${OBJS_P} sort.h 
	${CC} ${CCFLAGS} -L ./libft ${OBJS_P} -o ${NAME_P} -lft
	
${NAME_C}: ${LIBFT} ${OBJS_C} sort.h 
	${CC} ${CCFLAGS} -L ./libft ${OBJS_C} -o ${NAME_C} -lft



${LIBFT}:
	make bonus -C ./libft/

bonus: ${NAME_C} ${NAME_P}
	
all: ${NAME_P}

clean:
	rm -f ${OBJS_C} ${OBJS_P}

fclean: clean
	rm -f ${NAME_C} ${NAME_P}

re: fclean all

.PHONY: all clean fclean re
