/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:54:22 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/12 18:55:27 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_data *data)
{
	int	width;
	int	height;

	data->player.up = mlx_xpm_file_to_image(data->mlx,
			"./assets/player_up.xpm", &width, &height);
	data->player.down = mlx_xpm_file_to_image(data->mlx,
			"./assets/player_down.xpm", &width, &height);
	data->player.right = mlx_xpm_file_to_image(data->mlx,
			"./assets/player_right.xpm", &width, &height);
	data->player.left = mlx_xpm_file_to_image(data->mlx,
			"./assets/player_left.xpm", &width, &height);
}

void	set_collect(t_data *data)
{
	int	width;
	int	height;

	data->collectable.img = mlx_xpm_file_to_image(data->mlx,
			"./assets/collect1.xpm", &width, &height);
}

void	set_wall(t_data *data)
{
	int	width;
	int	height;

	data->walls = mlx_xpm_file_to_image(data->mlx, "./assets/wallx.xpm",
			&width, &height);
}

void	set_floor(t_data *data)
{
	int	width;
	int	height;

	data->floor = mlx_xpm_file_to_image(data->mlx, "./assets/floorx.xpm", \
	&width, &height);
}

void	set_asset(t_data *data)
{
	int	width;
	int	height;

	set_wall(data);
	set_floor(data);
	set_player(data);
	set_collect(data);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "./assets/exitx.xpm", \
	&width, &height);
	data->enemy = mlx_xpm_file_to_image(data->mlx, "./assets/enemyx.xpm", \
	&width, &height);
	data->gameover = mlx_xpm_file_to_image(data->mlx, "./assets/gameover.xpm", \
	&width, &height);
	data->grave = mlx_xpm_file_to_image(data->mlx, "./assets/grave.xpm", \
	&width, &height);
}
