# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 09:43:02 by mbui              #+#    #+#              #
#    Updated: 2020/10/16 16:36:33 by mbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC =  test.c parse.c float.c ft_printf.c utils.c print_csppercent.c convert_size.c
LIB = libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): getlibft
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

getlibft:
	make -C libft

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: clean fclean all re
