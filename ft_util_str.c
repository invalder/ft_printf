/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:50:42 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/13 13:08:16 by nnakarac         ###   ########.fr       */
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
