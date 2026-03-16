/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:26:54 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/16 14:26:55 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*ps;
	unsigned char			find;

	i = 0;
	ps = (const unsigned char *)s;
	find = (unsigned char)c;
	while (i < n)
	{
		if (ps[i] == find)
			return ((void *)&ps[i]);
		i++;
	}
	return (NULL);
}
