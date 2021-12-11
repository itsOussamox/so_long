/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:01:35 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/10 19:55:35 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	charcheck(t_data *data, int r, int c)
{
	char	ch;

	ch = data->map.array[r][c];
	if (ch != '1' && ch != '0' && ch != 'E' && ch != 'P' && ch != 'C'
		&& ch != '\n')
		return (0);
	return (1);
}

static void	colcheck(char *str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] && str[j] != '\n')
		j++;
	j--;
	if (str[i] != WALL || str[j] != WALL)
		end_game("MAP MUST BE SURROUNDED BY WALL", data);
}

static void	rowcheck(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != WALL)
			end_game("MAP MUST BE SURROUNDED BY WALL", data);
		i++;
	}
}

static void	ft_check(t_data *data, int r, int c)
{
	if (!charcheck(data, r, c))
		end_game("WRONG MAP CHARACTERS", data);
	if (data->map.array[r][c] == EXIT)
		data->exit_count++;
	if (data->map.array[r][c] == PLAYER)
	{
		data->player_count++;
		data->player.col = c;
		data->player.row = r;
	}
	if (data->map.array[r][c] == COLLECT)
		data->collectable.count++;
}

void	check_valid(t_data *data)
{
	int	r;
	int	c;
	int	i;

	i = 0;
	r = 0;
	c = 0;
	rowcheck(data->map.array[0], data);
	rowcheck(data->map.array[data->map.rows - 1], data);
	while (data->map.array[i])
		colcheck(data->map.array[i++], data);
	while (r < data->map.rows)
	{
		c = 0;
		while (c < data->map.cols)
		{
			ft_check(data, r, c);
			c++;
		}
		r++;
	}
	if (data->exit_count < 1 || data->collectable.count < 1
		|| data->player_count != 1)
		end_game("FAILED TO START THE GAME! (not enough/less elements)", data);
}
