/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:50:42 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/21 16:03:39 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, size_t len)
{
	write(1, str, len);
}

size_t	ft_putstri(char *str)
{
	size_t	len;

	len = 0;
	if (str)
	{
		while (*(str + len))
		{
			ft_putchar(*(str + len));
			len++;
		}
	}
	else
		len = ft_putstri("(null)");
	return (len);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str)
	{
		while (*str++)
			len++;
	}
	return (len);
}

size_t	ft_myatoi(char *ptr, t_prefix *t_pf, int is_prec)
{
	size_t	len;
	int		num;

	len = 0;
	num = 0;
	while (*(ptr + len) != '.' && !ft_specchk(ptr + len))
	{
		num = (num * 10) + (*(ptr + len) - '0');
		len++;
	}
	if (is_prec)
		t_pf->precision = num;
	else
		t_pf->width = num;
	return (len);
}
