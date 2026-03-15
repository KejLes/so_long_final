/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_struc_00.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:43:31 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/15 00:43:31 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_row(char **map)
{
	size_t	j;

	j = 0;
	while (map[j])
		j++;
	return (j);
}

size_t	count_collectibles(char **map)
{
	size_t	i;
	size_t	j;
	size_t	count;

	j = 0;
	count = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

size_t	get_position_x(char **map, char character)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == character)
				return (i);
			i++;
		}
		j++;
	}
	return (0);
}

size_t	get_position_y(char **map, char character)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == character)
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

t_game	*initialize_struct(char **mapa)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		free_matrix(mapa);
		error_and_exit("Failed to allocate memory for game");
	}
	game->map = mapa;
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = count_row(game->map);
	game->collectibles = count_collectibles(game->map);
	game->collect = 0;
	game->moves = 0;
	game->exit_x = get_position_x(game->map, EXIT);
	game->exit_y = get_position_y(game->map, EXIT);
	game->player_x = get_position_x(game->map, PLAYER);
	game->player_y = get_position_y(game->map, PLAYER);
	return (game);
}
