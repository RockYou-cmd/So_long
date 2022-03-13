/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:38:50 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/12 18:39:04 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_exit(int key, t_data *data)
{
	if (key == 53)
	{
		end_game(NULL, data);
	}
	return (0);
}

void	update_gameover(t_data *data, int r, int c)
{
	if (data->map.array[r][c] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->walls,
			c * SIZEX, r * SIZEY);
	if (data->map.array[r][c] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->gameover,
			c * SIZEX, r * SIZEY);
	if (data->map.array[r][c] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->gameover,
			c * SIZEX, r * SIZEY);
	if (data->map.array[r][c] == 'X')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->gameover,
			c * SIZEX, r * SIZEY);
		mlx_put_image_to_window(data->mlx, data->win, data->gameover,
			c * SIZEX, r * SIZEY);
	}
	if (data->map.array[r][c] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->gameover,
			c * SIZEX, r * SIZEY);
	}
}

void	gameover(t_data *data)
{
	int	r;
	int	c;

	mlx_clear_window(data->mlx, data->win);
	r = 0;
	while (r < data->map.rows)
	{
		c = 0;
		while (c < data->map.cols)
		{
			update_gameover(data, r, c);
			c++;
		}
		r++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->floor,
		data->player.col * SIZEX, data->player.row * SIZEY);
	mlx_put_image_to_window(data->mlx, data->win, data->grave,
		data->player.col * SIZEX, data->player.row * SIZEY);
	mlx_string_put(data->mlx, data->win,
		(data->map.cols / 2 * 32), 0, RED, "YOU LOSE!");
	mlx_string_put(data->mlx, data->win,
		2, 0, GREEN, "moves: ");
	data->death = 1;
	mlx_key_hook(data->win, game_exit, &data);
}
