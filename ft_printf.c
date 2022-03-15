/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:32:22 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/15 14:04:09 by nnakarac         ###   ########.fr       */
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
		printf("debug: %c\n", *ptr);
		if (*ptr == '%')
		{
			cur = ft_formatchk(ptr);
			if (cur >= 0)
			// buff = ft_appendfmt(ptr, cur, ap);
			cur++;
		}
		else
		{
			buff = ft_appendchr(buff, ptr);
			cur = 1;
		}
		ptr += cur;
	}
	if (buff)
	{
		ft_putstri(buff);
		free(buff);
	}
	va_end(ap);
	return (0);
}

ssize_t	ft_formatchk(char *ptr)
{
	size_t	len;

	len = 1;
	ptr++;
	if (*ptr == '%')
		return (2);
	while(!ft_specchk(ptr))
	{
		len += ft_flgchk(ptr);
		len += ft_widthchk(ptr);
		len += ft_precisechk(ptr);
		ptr += len;
	}
	if (ft_specchk(ptr))
		len += 1;
	else
		len = -1;
	return (len);
}

char	*ft_appendchr(char *buff, char *ptr)
{
	size_t buff_len;
	char	*new_buff;

	new_buff = NULL;
	if (buff)
		buff_len = ft_strlen(buff);
	else
		buff_len = 0;
	new_buff = malloc(sizeof(char) * buff_len + 2);
	if (!new_buff)
		return (NULL);
	ft_memcpy(new_buff, buff, buff_len);
	free(buff);
	ft_memcpy(new_buff + buff_len, ptr, 1);
	*(new_buff + buff_len + 2) = 0;
	return (new_buff);
}

char	*ft_appendfmt(char *buff, char *ptr, size_t cur, va_list ap)
{
	char	*new_buff;
	char	*pnt_buff;
	static t_prefix	*t_pre;

	if (*ptr == '%')
		return (ft_appendchr(buff, ptr));
	while (*ptr)
	{

	}
	// if (ft_specchk(ptr + cur))
	// 	pnt_buff = ft_printf_spec(ptr + cur, ap);
}

char	*ft_printf_spec(char *ptr, va_list ap)
{
	if (*ptr == 'c')
		return (ft_print_c(ap));
	if (*ptr == 's')
		return (ft_print_s(ap));
	if (*ptr == 'd' || *ptr == 'i')
		return (ft_print_d(ap));
	if (*ptr == 'p')
		return (ft_print_addr(ap));

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
