/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:32:22 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/19 00:01:59 by nnakarac         ###   ########.fr       */
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
	int		cur;
	int		len;

	cur = 0;
	len = 0;
	va_start(ap, fmt);
	ptr = (char *)fmt;
	buff = NULL;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			cur = ft_formatchk(ptr);
			if (cur > 0)
				buff = ft_appendfmt(buff, ptr + 1, &len, ap);
			else
			{
				if (buff)
					free(buff);
				return (0);
			}
		}
		else
		{
			buff = ft_appendchr(buff, ptr, &len);
			cur = 1;
		}
		ptr += cur;
	}
	if (buff)
	{
		ft_putnstr(buff, len);
		free(buff);
	}
	va_end(ap);
	return (len);
}

ssize_t	ft_formatchk(char *ptr)
{
	ssize_t	len;

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

char	*ft_appendchr(char *buff, char *ptr, int *len)
{
	size_t buff_len;
	char	*new_buff;

	new_buff = NULL;
	if (buff)
		buff_len = *len;
	else
		buff_len = 0;
	new_buff = malloc(sizeof(char) * (buff_len + 2));
	if (!new_buff)
		return (NULL);
	if (buff)
	{
		ft_memcpy(new_buff, buff, buff_len);
		free(buff);
	}
	ft_memcpy(new_buff + buff_len, ptr, 1);
	*(new_buff + buff_len + 1) = 0;
	*len += 1;
	return (new_buff);
}

char	*ft_append2str(char *buff, char c)
{
	size_t buff_len;
	char	*new_buff;

	new_buff = NULL;
	if (buff)
		buff_len = ft_strlen(buff);
	else
		buff_len = 0;
	new_buff = malloc(sizeof(char) * (buff_len + 2));
	if (!new_buff)
		return (NULL);
	if (buff)
	{
		ft_memcpy(new_buff, buff, buff_len);
		free(buff);
	}
	*(new_buff + buff_len) = c;
	*(new_buff + buff_len + 1) = 0;
	return (new_buff);
}

char	*ft_append2str_ul(char *buff, char c, int shift)
{
	size_t buff_len;
	char	*new_buff;

	if (shift)
	{
		if (c >= 'a' && c <= 'z')
			c -= 32;
	}
	new_buff = NULL;
	if (buff)
		buff_len = ft_strlen(buff);
	else
		buff_len = 0;
	new_buff = malloc(sizeof(char) * (buff_len + 2));
	if (!new_buff)
		return (NULL);
	if (buff)
	{
		ft_memcpy(new_buff, buff, buff_len);
		free(buff);
	}
	*(new_buff + buff_len) = c;
	*(new_buff + buff_len + 1) = 0;
	return (new_buff);
}

char	*ft_appendfmt(char *buff, char *ptr, int *len, va_list ap)
{
	char	*new_buff;
	char	*pnt_buff;
	int		pv_len;
	static t_prefix	t_pf;

	ft_freeprefix(&t_pf);
	new_buff = NULL;
	pnt_buff = NULL;
	pv_len = *len;
	if (*(ptr) == '%')
		return (ft_appendchr(buff, ptr, len));
	while (!ft_specchk(ptr))
	{
		t_pf.is_left = 0;
		t_pf.is_sign = 0;
		t_pf.is_space = 0;
		t_pf.is_preceed = 0;
		t_pf.is_iszero = 0;
		t_pf.width = 0;
		t_pf.precision = 0;
		ptr++;
	}
	if (ft_specchk(ptr))
	{
		pnt_buff = ft_printf_spec(ptr, ap, len, &t_pf);
		if (!pnt_buff)
		{
			free(buff);
			return (NULL);
		}
		new_buff = malloc(sizeof(char) * ((size_t)(*len) + 1));
		if (!new_buff)
		{
			free(buff);
			free(pnt_buff);
			return (NULL);
		}
		ft_memcpy(new_buff, buff, (size_t)(pv_len));
		ft_memcpy(new_buff + (size_t)(pv_len), pnt_buff, (size_t)(*len - pv_len));
		*(new_buff + *len) = 0;
		free(buff);
		free(pnt_buff);
		return (new_buff);

	}
	free(buff);
	return (NULL);
}

char	*ft_printf_spec(char *ptr, va_list ap, int *len, t_prefix *t_pf)
{
	if (*ptr == 'c')
		return (ft_print_c(ap, len));
	if (*ptr == 's')
		return (ft_print_s(ap, len));
	if (*ptr == 'd' || *ptr == 'i')
		return (ft_print_d(ap, len));
	if (*ptr == 'p')
		return (ft_print_p(ap, len));
	if (*ptr == 'u')
		return (ft_print_u(ap, len));
	if (*ptr == 'x')
		return (ft_print_x(ap, 0, 0, len));
	if (*ptr == 'X')
		return (ft_print_x(ap, 1, 0, len));
	ft_freeprefix(t_pf);
	return (NULL);
}

void	ft_freeprefix(t_prefix *t_pf)
{
	t_pf->is_left = 0;
	t_pf->is_sign = 0;
	t_pf->is_space = 0;
	t_pf->is_preceed = 0;
	t_pf->is_iszero = 0;
	t_pf->width = 0;
	t_pf->precision = 0;
}

// int	ft_is_left()
