/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:27:06 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 15:08:09 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_player(t_data *data)
{
	int	width;
	int	height;

	data->player.img = mlx_xpm_file_to_image(data->mlx,
			"./assets/playerx.xpm", &width, &height);
}

static void	set_collect(t_data *data)
{
	int	width;
	int	height;

	data->collectable.img = mlx_xpm_file_to_image(data->mlx,
			"./assets/collectx.xpm", &width, &height);
}

static void	set_wall(t_data *data)
{
	int	width;
	int	height;

	data->walls = mlx_xpm_file_to_image(data->mlx, "./assets/wallx.xpm",
			&width, &height);
}

static void	set_floor(t_data *data)
{
	int	width;
	int	height;

	data->floor = mlx_xpm_file_to_image(data->mlx, "./assets/floorx.xpm", \
	&width, &height);
}

void	set_asset(t_data *data)
{
	int	width;
	int	height;

	set_wall(data);
	set_floor(data);
	set_player(data);
	set_collect(data);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "./assets/exitx.xpm", \
	&width, &height);
	data->enemy_img = mlx_xpm_file_to_image(data->mlx, "./assets/enemyx.xpm", \
	&width, &height);
	data->dead_img = mlx_xpm_file_to_image(data->mlx, "./assets/deadx.xpm", \
	&width, &height);
}
