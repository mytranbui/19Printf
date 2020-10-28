# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 23:45:25 by mbui              #+#    #+#              #
#    Updated: 2020/10/28 23:45:46 by mbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLGS = -Wall -Wextra -Werror
LIB_DIR = libft
SRCS =	srcs/ft_printf.c \
		srcs/parse.c \
		srcs/parse_utils.c \
		srcs/convert_size.c \
		srcs/print_csppercent.c \
		srcs/print_di.c \
		srcs/print_o.c \
		srcs/print_u.c \
		srcs/print_x.c \
		srcs/print_f.c \
		srcs/utils.c \
		srcs/utils2.c \

OBJS =	ft_printf.o \
		parse.o \
		parse_utils.o \
		convert_size.o \
		print_csppercent.o \
		print_di.o \
		print_o.o \
		print_u.o \
		print_x.o \
		print_f.o \
		utils.o \
		utils2.o \

INCS = srcs/libftprintf.h

all: $(NAME)

$(NAME): getlibft
	@cp $(LIB_DIR)/libft.a $(NAME)
	@$(CC) -c $(FLGS) $(SRCS) $(INCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "compilation ok"

getlibft:
	@make -C $(LIB_DIR)

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -f ft_printf.h.gch
	@make clean -C libft
	@printf "Objects are removed correctly.\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft
	@printf "$(NAME) and $(LIB) are removed correctly.\n"

re: fclean all

.PHONY: all clean fclean re