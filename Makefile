NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = libft
SRCS =		srcs/ft_printf.c \
			srcs/parse.c \
			srcs/convert_size.c \
			srcs/print_csppercent.c \
			srcs/float.c \
			srcs/parse_utils.c \
			srcs/utils.c \
			srcs/utils2.c \
			srcs/test.c \

RESULT = 	ft_printf.o \
			parse.o \
			convert_size.o \
			print_csppercent.o \
			float.o \
			parse_utils.o \
			utils.o \
			utils2.o \
			test.o \

INCLUDES = srcs/libftprintf.h

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/libft.a $(NAME)
	@$(CC) -c $(CFLAGS) $(SRCS) $(INCLUDES)
	@ar rc $(NAME) $(RESULT)
	@ranlib $(NAME)
	@/bin/rm -f srcs/libftprintf.h.gch
	@echo "compilation ok"

clean:
	@/bin/rm -f $(RESULT)
	@/bin/rm -f libft/*.o
	@printf "Objects are removed correctly.\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIB_DIR)/libft.a
	@printf "$(NAME) and $(LIB) are removed correctly.\n"

re: fclean all

.PHONY: all clean fclean re
