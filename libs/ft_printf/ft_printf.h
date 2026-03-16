/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:23:31 by kcanales          #+#    #+#             */
/*   Updated: 2026/03/16 14:23:32 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *formato, ...);
int		ft_putchar(char c);
int		ft_putstring(char *s);
int		ft_putdigit(long number);
int		ft_putdigit_unsigned(long number);
int		ft_putpointer(void *numpointer);
int		ft_puthexa_lowercase(long number);
int		ft_puthexa_uppercase(long number);
int		ft_putnbr_base(unsigned long nbr, int base, int is_uppercase);
#endif