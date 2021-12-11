/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:41:52 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 12:50:38 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	static int	i = 1;
	int			count;
	int			prow;
	int			pcol;

	count = 0;
	prow = data->player.row;
	pcol = data->player.col;
	if (key == RIGHT && data->map.array[prow][pcol + 1] != WALL
			&& exi(data, key))
		move_right(data, &count);
	if (key == LEFT && data->map.array[prow][pcol - 1] != WALL
			&& exi(data, key))
		move_left(data, &count);
	if (key == DOWN && data->map.array[prow + 1][pcol] != WALL
			&& exi(data, key))
		move_down(data, &count);
	if (key == UP && data->map.array[prow - 1][pcol] != WALL
			&& exi(data, key))
		move_up(data, &count);
	if (key == 12)
		end_game(NULL, data);
	if (count)
		printf("Moves: [%d]\n", i++);
	return (render(data));
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
	render(&data);
	mlx_hook(data.win, 2, 1L << 0, move, &data);
	mlx_hook(data.win, 17, 0L, destroy_notify, &data);
	mlx_loop(data.mlx);
	return (0);
}
