/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:16:50 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 12:54:21 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	checkmap(char *line, int cols)
{
	int	len;

	len = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		len -= 1;
	if (len != cols)
		return (0);
	else
		return (1);
}

static void	file_ext(char *file, t_data *data)
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

static int	fillmap(t_data *data, char *new_line)
{
	char	**new_map;
	size_t	i;

	i = 0;
	data->map.rows = data->map.rows + 1;
	new_map = ft_calloc(sizeof(char *), (data->map.rows + 1));
	if (!new_map)
		end_game("MALLOC ERROR :(", data);
	while (data->map.array[i])
	{
		new_map[i] = data->map.array[i];
		i++;
	}
	new_map[i] = new_line;
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
		end_game("Failed to read from map file.", data);
	data->map.cols = ft_strlen(line) - 1;
	data->map.rows = 0;
	data->map.array[0] = NULL;
	while (line)
	{
		if (!checkmap(line, data->map.cols))
			end_game("WRONG MAP SIZE (NOT RECTANGULAR).", data);
		fillmap(data, line);
		line = get_next_line(fd);
	}
	close(fd);
}
