/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:03:14 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/12 18:37:05 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coll_up(t_data *data)
{
	int	r;
	int	c;

	r = 0;
	while (r < data->map.rows)
	{
		c = 0;
		while (c < data->map.cols)
		{
			if (data->map.array[r][c] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->collectable.img,
					c * SIZEX, r * SIZEY);
			}
			c++;
		}
		r++;
	}
}

int	coll_animation(t_data *data)
{
	static int	i;
	int			size;	

	if (i <= 10)
		data->collectable.img = mlx_xpm_file_to_image(data->mlx,
				"./assets/collect1.xpm", &size, &size);
	else if (i <= 20)
		data->collectable.img = mlx_xpm_file_to_image(data->mlx,
				"./assets/collect2o.xpm", &size, &size);
	else if (i <= 30)
		data->collectable.img = mlx_xpm_file_to_image(data->mlx,
				"./assets/collect3o.xpm", &size, &size);
	else if (i <= 40)
		data->collectable.img = mlx_xpm_file_to_image(data->mlx,
				"./assets/collect4o.xpm", &size, &size);
	else if (i <= 50)
		data->collectable.img = mlx_xpm_file_to_image(data->mlx,
				"./assets/collect5o.xpm", &size, &size);
	else if (i <= 60)
		data->collectable.img = mlx_xpm_file_to_image(data->mlx,
				"./assets/collect6o.xpm", &size, &size);
	if (i++ == 60)
		i = 0;
	coll_up(data);
	return (0);
}
