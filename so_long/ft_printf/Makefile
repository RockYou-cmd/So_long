CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

AR = ar rcs
FILES= ft_printf ft_printing ft_itoa ft_print_hex\
	   ft_print_ptr ft_print_unsigned ft_putchar_fd
SRC = $(FILES:=.c)
OBJ = $(FILES:=.o)

NAME = ft_printf.a

all:$(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
re:	fclean all
