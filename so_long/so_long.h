/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:54:00 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/13 13:14:26 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define RIGHT 2
# define LEFT 0
# define DOWN 1
# define UP 13
# define EXIT 'E'
# define PLAYER 'P'
# define COLLECT 'C'
# define EMPTY '0'
# define WALL '1'
# define SIZEX 32
# define SIZEY 32

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_player
{
	void	*up;
	int		row;
	int		col;
}				t_player;

typedef struct s_map {
	char	**array;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_collectable {
	void	*img;
	int		count;
}				t_collectable;

typedef struct s_data {
	void			*mlx;
	void			*win;
	t_player		player;
	t_collectable	collectable;
	void			*floor;
	void			*walls;
	void			*exit_img;
	int				exit_count;
	int				player_count;
	t_map			map;
}				t_data;

void	game_start(t_data *data);
void	game_window(t_data *data);
void	end_game(char *error_message, t_data *data);
void	read_map(char *file, t_data *data);
void	check_valid(t_data *data);
void	set_asset(t_data *data);
int		update(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_up(t_data *data);
int		move(int key, t_data *data);
char	*ft_read_and_save(int fd, char *save);

#endif
