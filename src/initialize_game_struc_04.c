/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_struc_04.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:44:07 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/15 00:44:07 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_exit_open_texture(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/exit_open.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	game->sprites->exit_open = mlx_texture_to_image(game->mlx, imagen);
	if (!game->sprites->exit_open)
		error_mlx_and_free_struct(game, "Problem with load_png");
	mlx_delete_texture (imagen);
}
