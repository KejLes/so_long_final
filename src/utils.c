/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:44:46 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/15 00:44:46 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_matrix(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static	void	next_check_files(char *map)
{
	int	fd;

	fd = open("./textures/maradona_right.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/maradona_up.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/messi.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/pelotita.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/trail.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
}

void	check_files(char *map)
{
	int	fd;

	fd = open("./textures/flowers.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/god.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/maradona_down.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/maradona_left.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	next_check_files(map);
}
