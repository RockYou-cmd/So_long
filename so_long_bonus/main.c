/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:35:51 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/12 18:56:24 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_string(t_data *data)
{
	char	*s;

	s = ft_itoa(++data->mcount);
	mlx_string_put(data->mlx, data->win, 70, 0, GREEN, s);
	free(s);
}

int	exi(t_data *data, int key)
{
	int	prow;
	int	pcol;

	prow = data->player.row;
	pcol = data->player.col;
	if (key == RIGHT)
		if (data->map.array[prow][pcol + 1] == EXIT && data->collectable.count)
			return (0);
	if (key == LEFT)
		if (data->map.array[prow][pcol - 1] == EXIT && data->collectable.count)
			return (0);
	if (key == DOWN)
		if (data->map.array[prow + 1][pcol] == EXIT && data->collectable.count)
			return (0);
	if (key == UP)
		if (data->map.array[prow - 1][pcol] == EXIT && data->collectable.count)
			return (0);
	return (1);
}

int	move(int key, t_data *data)
{
	data->key = key;
	if (key == RIGHT && data->map.array[data->player.row]
		[data->player.col + 1] != WALL && exi(data, key))
		move_right(data);
	else if (key == LEFT && data->map.array[data->player.row]
		[data->player.col - 1] != WALL && exi(data, key))
		move_left(data);
	else if (key == DOWN && data->map.array[data->player.row + 1]
		[data->player.col] != WALL && exi(data, key))
		move_down(data);
	else if (key == UP && data->map.array[data->player.row - 1]
		[data->player.col] != WALL && exi(data, key))
		move_up(data);
	else if (key == 53)
		end_game(NULL, data);
	else
		return (0);
	if (data->map.array[data->player.row][data->player.col] == ENEMY)
		gameover(data);
	else
		update(data);
	put_string(data);
	return (0);
}

int	main(int argc, char **av)
{
	t_data	data;

	game_start(&data);
	if (argc != 2)
		end_game("WRONG MAP", &data);
	read_map(av[1], &data);
	check_valid(&data);
	game_window(&data);
	set_asset(&data);
	update(&data);
	mlx_key_hook(data.win, move, &data);
	mlx_loop_hook(data.mlx, coll_animation, &data);
	mlx_loop(data.mlx);
	return (0);
}
