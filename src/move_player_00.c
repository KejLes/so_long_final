/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:44:20 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/16 19:54:41 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_direction_y(t_game *game, char move_dir)
{
	int	d_x;
	int	d_y;

	d_x = 0;
	d_y = 0;
	if (move_dir == 'u')
	{
		d_y = -1;
		move_player_up(game, d_x, d_y);
	}
	else if (move_dir == 'd')
	{
		d_y = 1;
		move_player_down(game, d_x, d_y);
	}
}

static void	move_direction_x(t_game *game, char move_dir)
{
	int	d_x;
	int	d_y;

	d_x = 0;
	d_y = 0;
	if (move_dir == 'r')
	{
		d_x = 1;
		move_player_right(game, d_x, d_y);
	}
	else if (move_dir == 'l')
	{
		d_x = -1;
		move_player_left(game, d_x, d_y);
	}
}

static void	move_player(t_game *game, char direction_axis, char move_dir)
{
	if (direction_axis == 'y')
		move_direction_y(game, move_dir);
	else if (direction_axis == 'x')
		move_direction_x(game, move_dir);
	if (game->collect == game->collectibles)
		open_exit(game);
	if (game->map[game->player_y][game->player_x] == EXIT_OPEN)
		print_final_exit(game);
}

void	my_keyfuncion(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = (t_game *) data;
	if (mlx_is_key_down(game->mlx, KEY_ESC))
	{
		free_matrix(game->map);
		mlx_close_window(game->mlx);
	}
	if (keydata.key == ARROW_UP
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, 'y', 'u');
	if (keydata.key == ARROW_RIGHT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, 'x', 'r');
	if (keydata.key == ARROW_DOWN
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, 'y', 'd');
	if (keydata.key == ARROW_LEFT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, 'x', 'l');
}

void	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_matrix(game->map);
	mlx_close_window(game->mlx);
}
