/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:43:00 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 16:12:50 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	image_init(t_data *data)
{
	data->dead_img = NULL;
	data->enemy_img = NULL;
	data->exit_img = NULL;
	data->floor = NULL;
	data->player.img = NULL;
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
	data->dead = 0;
	image_init(data);
}

void	game_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
		end_game("MLX INIT ERROR", data);
	data->win = mlx_new_window(data->mlx, SIZEX * data->map.cols, \
	SIZEY * (data->map.rows + 1), "so_long");
}
