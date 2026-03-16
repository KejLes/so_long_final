/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:44:13 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/16 19:48:25 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	char	**map;

	if (argc != 2)
		msg_and_exit("Example to execute: ./so_long map.ber");
	map = check_map(argv[1]);
	check_files();
	game = initialize_struct(map);
	check_map_final(game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->map_width * PIXELS, game->map_height * PIXELS,
			"so_long", true);
	if (!game->mlx)
		error_and_free_struct(game, "MLX initialization failed", true);
	initialize_struct_img(game);
	fill_map(game);
	mlx_close_hook(game->mlx, &close_window, game);
	mlx_key_hook(game->mlx, &my_keyfuncion, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game->sprites);
	free(game);
	exit (0);
}
