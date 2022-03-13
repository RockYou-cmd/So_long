/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:59:21 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/12 18:46:44 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(t_data *data)
{
	if (data->key == UP)
		mlx_put_image_to_window(data->mlx, data->win, data->player.up,
			data->player.col * SIZEX, data->player.row * SIZEY);
	else if (data->key == DOWN)
		mlx_put_image_to_window(data->mlx, data->win, data->player.down,
			data->player.col * SIZEX, data->player.row * SIZEY);
	else if (data->key == RIGHT)
		mlx_put_image_to_window(data->mlx, data->win, data->player.right,
			data->player.col * SIZEX, data->player.row * SIZEY);
	else if (data->key == LEFT)
		mlx_put_image_to_window(data->mlx, data->win, data->player.left,
			data->player.col * SIZEX, data->player.row * SIZEY);
	return (0);
}

void	check_render(t_data *data, int r, int c)
{
	if (data->map.array[r][c] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->walls,
			c * SIZEX, r * SIZEY);
	if (data->map.array[r][c] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor,
			c * SIZEX, r * SIZEY);
	if (data->map.array[r][c] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->floor,
			c * SIZEX, r * SIZEY);
	if (data->map.array[r][c] == 'X')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->floor,
			c * SIZEX, r * SIZEY);
		mlx_put_image_to_window(data->mlx, data->win, data->enemy,
			c * SIZEX, r * SIZEY);
	}
	if (data->map.array[r][c] == 'E')
	{
		if (!data->collectable.count)
			mlx_put_image_to_window(data->mlx, data->win, data->exit_img,
				c * SIZEX, r * SIZEY);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->walls,
				c * SIZEX, r * SIZEY);
	}
}

int	update(t_data *data)
{
	int	r;
	int	c;

	if (data->map.array[data->player.row][data->player.col] == EXIT)
		end_game(NULL, data);
	r = 0;
	while (r < data->map.rows)
	{
		c = 0;
		while (c < data->map.cols)
		{
			check_render(data, r, c);
			c++;
		}
		r++;
	}
	check_player(data);
	mlx_string_put(data->mlx, data->win, 2, 0, GREEN, "moves: ");
	return (1);
}
