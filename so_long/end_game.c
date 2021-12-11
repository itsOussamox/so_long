/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:08:16 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 12:42:04 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_data *data)
{
	if (data->walls)
		mlx_destroy_image(data->mlx, data->walls);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
	if (data->collectable.img)
		mlx_destroy_image(data->mlx, data->collectable.img);
	if (data->player.img)
		mlx_destroy_image(data->mlx, data->player.img);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
}

int	destroy_notify(t_data *data)
{
	end_game(NULL, data);
	return (1);
}

void	end_game(char *error_message, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.rows)
		if (data->map.array[i])
			free(data->map.array[i++]);
	if (data->map.array)
		free(data->map.array);
	if (error_message)
		exit(printf("Error\n%s\n", error_message));
	if (!error_message)
	{
		destroy_images(data);
		printf("\n|!|!|!|!|!|!|!|GAME CLOSED SUCCESFULLY|!|!|!|!|!|!|!|\n");
		exit(EXIT_SUCCESS);
	}
}
