/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:27:47 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/16 14:27:48 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ps;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	ps = malloc(len + 1);
	if (ps == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ps[i] = str[i];
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
