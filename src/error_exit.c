/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:43:21 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/15 00:43:21 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_exit(char *message)
{
	ft_putendl_fd("Error", 2);
	perror(message);
	exit(1);
}

void	msg_and_exit(char *message)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("There is a mistake!\n", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}

void	error_map_free(char *message, char *map_line, char **map_array)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	if (map_line)
		free(map_line);
	if (map_array)
		free_matrix(map_array);
	exit(1);
}

void	error_and_free_struct(t_game *game, char *message, bool use_perror)
{
	if (game->map)
		free_matrix(game->map);
	if (game)
		free(game);
	if (use_perror)
		perror(message);
	else
		ft_putendl_fd("Error", 2);
	ft_putstr_fd(message, 2);
	exit(1);
}

void	error_mlx_and_free_struct(t_game *game, char *message)
{
	mlx_terminate(game->mlx);
	error_and_free_struct(game, message, true);
}
