/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:41:52 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 16:49:34 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	exi(t_data *data, int key)
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

static void	handle_keys(int key, t_data *data, int *count)
{
	int	prow;
	int	pcol;

	prow = data->player.row;
	pcol = data->player.col;
	if (key == RIGHT && data->map.array[prow][pcol + 1] != WALL
			&& exi(data, key))
		move_right(data, count);
	if (key == LEFT && data->map.array[prow][pcol - 1] != WALL
			&& exi(data, key))
		move_left(data, count);
	if (key == DOWN && data->map.array[prow + 1][pcol] != WALL
			&& exi(data, key))
		move_down(data, count);
	if (key == UP && data->map.array[prow - 1][pcol] != WALL
			&& exi(data, key))
		move_up(data, count);
}

static void	print_moves(t_data *data, int nb, int *count)
{
	char	*moves;
	int	height;

	if (*count)
		*count = 0;
	height = (SIZEY * (data->map.rows + 1) - 30);
	moves = ft_itoa(nb);
	mlx_string_put(data->mlx, data->win, SIZEX - 30, height, 175, "Moves : ");
	mlx_string_put(data->mlx, data->win, SIZEX + 50, height, GREEN, moves);
	free(moves);
}

int	move(int key, t_data *data)
{
	static int	i = 0;
	int			count;

	count = 0;
	if (key == 12)
	{
		printf("\n   IDEK FEH xD  \n");
		end_game(NULL, data);
	} 
	check_enemy(key, data);
	if (data->dead == 0)
	{
		handle_keys(key, data, &count);
		render(data);
		if (count)
			print_moves(data , ++i, &count);
		else
			print_moves(data , i, &count);
	}
	else
		game_end(data);
	return (1);
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
