/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_chk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:59:27 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/14 22:49:39 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_flgchk(char *ptr)
{
	if (*ptr == '-' || *ptr == '+' || *ptr == ' ' || *ptr == '#' || *ptr == '0')
		return (1);
	return (0);
}

size_t	ft_widthchk(char *ptr)
{
	if (*ptr == '*')
		return (1);
	if (ft_isdigit(*ptr))
	{
		return (ft_nbrcnt(ptr));
	}
	return (0);
}

size_t	ft_precisechk(char *ptr)
{
	if (*ptr == '.')
	{
		if (*(ptr + 1) == '*')
			return (2);
		else if (ft_isdigit(*(ptr + 1)))
			return (ft_nbrcnt(ptr + 1) + 1);
		else
			return (1);
	}
	return (0);
}

size_t	ft_specchk(char *ptr)
{
	if (*ptr == 'c' || *ptr == 's' || *ptr == 'd' || *ptr == 'i' || \
	*ptr == 'p' || *ptr == 'u' || *ptr == 'o' || *ptr == 'x' || *ptr == 'X')
		return (1);
	return (0);
}

size_t	ft_isdigit(char c)
{
	return ((c >= '0' && c <= '9'));
}

size_t	ft_nbrcnt(char *ptr)
{
	size_t	len;

	len = 0;
	while (ft_isdigit(*(ptr++)))
		len++;
	return (len);
}
