/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:49:42 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 12:52:08 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *data, int *count)
{
	int	prow;
	int	pcol;

	*count = *count + 1;
	data->player.col += 1;
	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow][pcol] == COLLECT)
	{
		data->map.array[prow][pcol] = EMPTY;
		data->collectable.count--;
	}
}

void	move_left(t_data *data, int *count)
{
	int	prow;
	int	pcol;

	*count = *count + 1;
	data->player.col -= 1;
	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow][pcol] == COLLECT)
	{
		data->map.array[prow][pcol] = EMPTY;
		data->collectable.count--;
	}
}

void	move_down(t_data *data, int *count)
{
	int	prow;
	int	pcol;

	*count = *count + 1;
	data->player.row += 1;
	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow][pcol] == COLLECT)
	{
		data->map.array[prow][pcol] = EMPTY;
		data->collectable.count--;
	}
}

void	move_up(t_data *data, int *count)
{
	int	prow;
	int	pcol;

	*count = *count + 1;
	data->player.row -= 1;
	prow = data->player.row;
	pcol = data->player.col;
	if (data->map.array[prow][pcol] == COLLECT)
	{
		data->map.array[prow][pcol] = EMPTY;
		data->collectable.count--;
	}
}
