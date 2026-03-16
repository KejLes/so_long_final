/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:28:12 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/16 14:28:13 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*newstrs;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	newstrs = (char *)malloc(len + 1);
	if (newstrs == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstrs[i] = f(i, s[i]);
		i++;
	}
	newstrs[len] = '\0';
	return (newstrs);
}
