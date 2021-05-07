# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 17:52:24 by jacher            #+#    #+#              #
#    Updated: 2021/03/16 12:08:53 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CCFLAGS = -Wall -Werror -Wextra

EXE1 = ft_checker/checker

EXE2 = ft_push_swap/push_swap

${EXE1}: sort.h
	make -C ./ft_checker
	cp ./ft_checker/checker .

${EXE2}: sort.h
	make -C ./ft_push_swap
	cp ./ft_push_swap/push_swap .

all:  ${EXE1} ${EXE2}

make: all

clean:
	make clean -C ./ft_checker
	make clean -C ./ft_push_swap
	make clean -C ./libft

fclean: clean
	make fclean -C ./ft_checker
	make fclean -C ./ft_push_swap
	make fclean -C ./libft
	rm checker
	rm push_swap

re: fclean all

.PHONY: all clean fclean re
