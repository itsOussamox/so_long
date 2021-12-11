/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:17:26 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/11 16:35:13 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define RIGHT 2
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define LEFT 0
# define DOWN 1
# define UP 13
# define EXIT 'E'
# define PLAYER 'P'
# define COLLECT 'C'
# define EMPTY '0'
# define ENEMY 'X'
# define WALL '1'
# define SIZEX 32
# define SIZEY 32

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

typedef struct s_player
{
	void	*img;
	int		row;
	int		col;
}				t_player;

typedef struct s_map {
	char	**array;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_collectable {
	void	*img;
	int		count;
}				t_collectable;

typedef struct s_data {
	void			*mlx;
	void			*win;
	t_player		player;
	t_collectable	collectable;
	void			*floor;
	void			*walls;
	void			*exit_img;
	void			*enemy_img;
	void			*dead_img;
	int				move_count;
	int				exit_count;
	int				player_count;
	int				dead;
	t_map			map;
}				t_data;

void	check_enemy(int key, t_data *data);
void	game_start(t_data *data);
void	game_window(t_data *data);
void	end_game(char *error_message, t_data *data);
void	game_end(t_data *data);
void	read_map(char *file, t_data *data);
void	check_valid(t_data *data);
void	set_asset(t_data *data);
int		render(t_data *data);
void	move_right(t_data *data, int *count);
void	move_left(t_data *data, int *count);
void	move_down(t_data *data, int *count);
void	move_up(t_data *data, int *count);
int		destroy_notify(t_data *data);
int		move(int key, t_data *data);
int		get_color(int nb);

#endif
