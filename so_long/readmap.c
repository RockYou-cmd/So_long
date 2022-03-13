/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:40:40 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/13 20:24:58 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkmap(char *line, int cols)
{
	int	len;

	len = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		len = len - 1;
	if (len != cols)
		return (0);
	else
		return (1);
}

void	file_ext(char *file, t_data *data)
{
	char	*ber;

	ber = ft_strnstr(file, ".ber", ft_strlen(file));
	if (ber)
	{
		if (ber == file + ft_strlen(file) - 4)
			return ;
	}
	end_game("ERROR MAP EXTENSION", data);
}

int	fillmap(t_data *data, char *line)
{
	char			**new_map;
	unsigned long	i;

	i = 0;
	data->map.rows = data->map.rows + 1;
	new_map = ft_calloc(sizeof(char *), (data->map.rows + 1));
	if (!new_map)
		end_game("MALLOC ERROR", data);
	while (data->map.array[i])
	{
		new_map[i] = data->map.array[i];
		i++;
	}
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(data->map.array);
	data->map.array = new_map;
	return (0);
}

void	read_map(char *file, t_data *data)
{
	int		fd;
	char	*line;

	file_ext(file, data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		end_game("Couldn't open map file.", data);
	line = get_next_line(fd);
	if (!line)
		end_game("Failed to read map", data);
	data->map.cols = ft_strlen(line) - 1;
	data->map.rows = 0;
	data->map.array[0] = NULL;
	while (line)
	{
		if (!checkmap(line, data->map.cols))
			end_game("WRONG MAP SIZE.", data);
		fillmap(data, line);
		line = get_next_line(fd);
	}
	close(fd);
}
