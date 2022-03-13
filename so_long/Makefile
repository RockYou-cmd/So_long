# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 14:03:17 by ael-korc          #+#    #+#              #
#    Updated: 2022/03/13 20:32:08 by ael-korc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

HEADER = so_long.h\
		gnl/get_next_line.h\
		libft/libft.h\
		ft_printf/ft_printf.h\

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/ft_printf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c \
	readmap.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	end_game.c \
	game_start.c \
	check_map.c \
	images.c \
	update_game.c \
	move_handler.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME) clean
	
$(NAME): $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) $(HEADER) 
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT_LIB) $(PRINTF_LIB) $(OBJS) -o $(NAME)
	

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)
	
clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	clear

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT_LIB)
	rm -rf $(PRINTF_LIB)

re: fclean all
.PHONY: all clean fclean re bonus
