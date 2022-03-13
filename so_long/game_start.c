/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:39:26 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/13 11:13:04 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_init(t_data *data)
{
	data->exit_img = NULL;
	data->floor = NULL;
	data->player.up = NULL;
	data->walls = NULL;
	data->collectable.img = NULL;
	data->win = NULL;
}

void	game_start(t_data *data)
{	
	data->map.array = malloc(sizeof(char *));
	if (!data->map.array)
		end_game("---> MALLOC MAP ARRAY", data);
	data->collectable.count = 0;
	data->exit_count = 0;
	data->player_count = 0;
	image_init(data);
}

void	game_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
		end_game("MLX INIT ERROR", data);
	data->win = mlx_new_window(data->mlx, SIZEX * data->map.cols, \
	SIZEY * (data->map.rows), "so_long");
}
