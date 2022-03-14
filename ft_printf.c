/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:32:22 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/14 17:29:14 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
%[flags][width][.precision]specifier
[flags]
'-'	Left-justify within the given field width; Right justification is the default (see width sub-specifier).
'+'	Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers.
	By default, only negative numbers are preceded with a - sign.
' '	If no sign is going to be written, a blank space is inserted before the value.
'#' Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
'0' Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).

[width]
(number)	Minimum number of characters to be printed. If the value to be printed is shorter than this number,
			the result is padded with blank spaces. The value is not truncated even if the result is larger.
'*'			The width is not specified in the format string, but as an additional integer value argument preceding the argument
			that has to be formatted.

[.precision]
.number		For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written.
			If the value to be written is shorter than this number, the result is padded with leading zeros.
			The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.
.*			The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.
*/

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*ptr;
	char	*buff;
	size_t	cur;

	va_start(ap, fmt);
	ptr = (char *)fmt;
	buff = NULL;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			cur = ft_formatchk(ptr);
		}

	}
	va_end(ap);
	return (0);
}

size_t	ft_formatchk(char *ptr)
{
	size_t	len;

	len = 1;
	ptr++;
	if (*ptr == '%')
		return (2);
	while(!ft_isspecifier(ptr))
	{
		len += ft_flgchk(ptr);
		len += ft_widthchk(ptr);
		len += ft_precisechk(ptr);
		len += ft_specchk(ptr);
		ptr += len;
	}
	return (len);
}

// char	*ft_flagchk(const char *fmt, char *buff, va_list ap)
// {
// 	char	*ptr;

// 	ptr = (char *)fmt;
// 	if (*ptr != '%')
// 		return (buff);
// 	ptr++;
// 	if (*ptr == '%')
// 		return (ft_buff_join(buff, "%"))
// }
