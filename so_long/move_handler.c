/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:39:47 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/13 14:13:32 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *data)
{
	int	prow;
	int	pcol;

	data->player.col += 1;
	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow][pcol] == COLLECT)
	{
		data->map.array[prow][pcol] = PLAYER;
		data->collectable.count--;
	}
	ft_printf("Moves: [%d]\n", data->player_count++);
}

void	move_left(t_data *data)
{
	int	prow;
	int	pcol;

	data->player.col -= 1;
	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow][pcol] == COLLECT)
	{
		data->map.array[prow][pcol] = PLAYER;
		data->collectable.count--;
	}
	ft_printf("Moves: [%d]\n", data->player_count++);
}

void	move_down(t_data *data)
{
	int	prow;
	int	pcol;

	data->player.row += 1;
	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow][pcol] == COLLECT)
	{
		data->map.array[prow][pcol] = PLAYER;
		data->collectable.count--;
	}
	ft_printf("Moves: [%d]\n", data->player_count++);
}

void	move_up(t_data *data)
{
	int	prow;
	int	pcol;

	data->player.row -= 1;
	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow][pcol] == COLLECT)
	{
		data->map.array[prow][pcol] = PLAYER;
		data->collectable.count--;
	}
	ft_printf("Moves: [%d]\n", data->player_count++);
}
