/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:27:41 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 15:08:26 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	game_over(t_data *data)
{
	data->dead = 1;
	render(data);
}

void	check_enemy(int key, t_data *data)
{
	int	prow;
	int	pcol;

	prow = data->player.row;
	pcol = data->player.col;
	if (key == RIGHT && data->map.array[prow][pcol + 1] == ENEMY)
		game_over(data);
	if (key == LEFT && data->map.array[prow][pcol - 1] == ENEMY)
		game_over(data);
	if (key == DOWN && data->map.array[prow + 1][pcol] == ENEMY)
		game_over(data);
	if (key == UP && data->map.array[prow - 1][pcol] == ENEMY)
		game_over(data);
}