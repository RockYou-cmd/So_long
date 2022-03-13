# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 14:31:52 by ael-korc          #+#    #+#              #
#    Updated: 2022/03/13 20:33:45 by ael-korc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long_bonus

HEADER = so_long.h\
		gnl/get_next_line.h\
		libft/libft.h\

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

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
	gameover.c \
	update_game.c \
	move_handler.c \
	animation.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME) clean
	
$(NAME): $(OBJS) $(LIBFT_LIB) $(HEADER) 
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT_LIB) $(OBJS) -o $(NAME)
	

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
	
clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	clear
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	clear

re: fclean all
	clear

