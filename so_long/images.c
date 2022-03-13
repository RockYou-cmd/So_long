/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:54:22 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/13 13:58:54 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_collect(t_data *data)
{
	int	width;
	int	height;

	data->collectable.img = mlx_xpm_file_to_image(data->mlx,
			"./assets/collec1.xpm", &width, &height);
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
	set_collect(data);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "./assets/exitx.xpm", \
	&width, &height);
	data->player.up = mlx_xpm_file_to_image(data->mlx,
			"./assets/player_up.xpm", \
			&width, &height);
	data->collectable.img = mlx_xpm_file_to_image(data->mlx,
			"./assets/collect1.xpm", \
			&width, &height);
}
