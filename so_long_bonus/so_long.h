/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:54:00 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/12 18:54:05 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define GREEN 0x0000F190
# define RED 0x00FF0000
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
# define ENEMY 'X'

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

typedef struct s_player
{
	void	*up;
	void	*down;
	void	*right;
	void	*left;
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
	void			*enemy;
	void			*grave;
	void			*exit_img;
	void			*gameover;
	int				exit_count;
	int				player_count;
	int				key;
	t_map			map;
	int				death;
	int				mcount;
}				t_data;

void	game_start(t_data *data);
void	game_window(t_data *data);
void	end_game(char *error_message, t_data *data);
void	read_map(char *file, t_data *data);
void	check_valid(t_data *data);
void	set_asset(t_data *data);
int		update(t_data *data);
void	gameover(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_up(t_data *data);
int		move(int key, t_data *data);
int		check_player(t_data *data);
int		coll_animation(t_data *data);
char	*ft_read_and_save(int fd, char *save);
int		coll_animation(t_data *data);

#endif
