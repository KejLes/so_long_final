/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:44:35 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/15 00:44:35 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_game *game)
{
	game->sprites->exit->instances[0].enabled = false;
	game->map[game->exit_y][game->exit_x] = EXIT_OPEN;
	if (game->sprites->exit_open->count == 0)
		mlx_image_to_window(game->mlx, game->sprites->exit_open,
			game->exit_x * PIXELS, game->exit_y * PIXELS);
	game->sprites->exit = game->sprites->exit_open;
	game->sprites->exit->instances[0].enabled = true;
}

void	print_moves(t_game *game)
{
	game->moves++;
	ft_printf("That's it, don't stop! Keep going! Moves: %d\n", game->moves);
}

void	print_final_exit(t_game *game)
{
	ft_printf("\nResounding success!\nYou've earned eternal glory.\n");
	mlx_close_window(game->mlx);
}
