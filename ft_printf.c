/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:32:22 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/13 17:56:50 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
%[flags][width][.precision]specifier
*/

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*ptr;
	char	*buff;

	va_start(ap, fmt);
	ptr = (char *)fmt;
	buff = NULL;
	while (*ptr)
	{
		if (*ptr == '%')
		{

		}

	}
	va_end(ap);
	return (0);
}

char	*ft_flagchk(const char *fmt, char *buff, va_list ap)
{
	char	*ptr;

	ptr = (char *)fmt;
	if (*ptr != '%')
		return (buff);
	ptr++;
	if (*ptr == '%')
		return (ft_buff_join(buff, "%"))
}
