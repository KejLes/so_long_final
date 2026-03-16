/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:28:00 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/16 14:28:01 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;
	size_t	lensrc;	

	if (size == 0 && (!dest || !src))
		return (0);
	lensrc = ft_strlen(src);
	lendest = ft_strlen(dest);
	if (size <= lendest)
		return (lensrc + size);
	i = 0;
	while (src[i] != '\0' && (lendest + i) < size - 1)
	{
		dest[lendest + i] = src[i];
		i++;
	}
	if (size)
		dest[lendest + i] = '\0';
	return (lendest + lensrc);
}
