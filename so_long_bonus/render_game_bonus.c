/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:29:03 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 16:58:37 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	basic_render(t_data *data, int r, int c)
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
	if (data->map.array[r][c] == 'E')
	{
		if (!data->collectable.count)
			mlx_put_image_to_window(data->mlx, data->win, data->exit_img,
				c * SIZEX, r * SIZEY);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->walls,
				c * SIZEX, r * SIZEY);
	}
	if (data->map.array[r][c] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collectable.img,
			c * SIZEX, r * SIZEY);
}

static void	enemy_render(t_data *data, int r, int c)
{
	if (data->map.array[r][c] == 'X')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy_img,
			c * SIZEX, r * SIZEY);
}

static void	check_render(t_data *data, int r, int c)
{
	basic_render(data, r, c);
	enemy_render(data, r, c);
}

static void	render_player(t_data *data)
{
	if (data->dead == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->player.img,
			data->player.col * SIZEX, data->player.row * SIZEY);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->dead_img,
			data->player.col * SIZEX, data->player.row * SIZEY);
}

int	render(t_data *data)
{
	int	r;
	int	c;

	mlx_clear_window(data->mlx, data->win);
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
	render_player(data);
	return (1);
}
