/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:44:46 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/16 19:49:32 by kcanales         ###   ########.fr       */
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

static	void	next_check_files(void)
{
	int	fd;

	fd = open("./textures/saucer_squash_right.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/saucer_squash_up.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/exit_close.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/sun.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/sky.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
}

void	check_files(void)
{
	int	fd;

	fd = open("./textures/cloud.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/exit_open.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/saucer_squash_down.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	fd = open("./textures/saucer_squash_left.png", O_RDONLY);
	if (fd == -1)
		error_and_exit("Texture files are missing, check the textures folder");
	close(fd);
	next_check_files();
}
