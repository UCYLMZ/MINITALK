NAME=libftprintf.a

SRCS= ft_printf.c print_char.c\
	print_int.c print_string.c print_ptr.c\
	print_hex.c print_unsigned.c

OBJS= $(SRCS:.c=.o)	

CC=gcc

RM= rm -rf

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean: clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re