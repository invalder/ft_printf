/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:32:22 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/24 16:35:58 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
%[flags][width][.precision]specifier
[flags]
'-'	Left-justify within the given field width; Right
	justification is the default (see width sub-specifier).
'+'	Forces to preceed the result with a plus or minus sign
	(+ or -) even for positive numbers.
	By default, only negative numbers are preceded with a - sign.
' '	If no sign is going to be written, a blank space is inserted
	before the value.
'#' Used with o, x or X specifiers the value is preceeded with 0,
	0x or 0X respectively for values different than zero.
'0' Left-pads the number with zeroes (0) instead of spaces when
	padding is specified (see width sub-specifier).

[width]
(number)	Minimum number of characters to be printed. If the value
			to be printed is shorter than this number,
			the result is padded with blank spaces. The value is not
			truncated even if the result is larger.
'*'			The width is not specified in the format string, but as an
			additional integer value argument preceding the argument
			that has to be formatted.

[.precision]
.number		For integer specifiers (d, i, o, u, x, X): precision specifies
			the minimum number of digits to be written.
			If the value to be written is shorter than this number,
			the result is padded with leading zeros.
			The value is not truncated even if the result is longer.
			A precision of 0 means that no character is written for the value 0.
.*			The precision is not specified in the format string,
			but as an additional integer value argument preceding
			the argument that has to be formatted.
*/

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*ptr;
	char	*buff;
	int		len;

	len = 0;
	va_start(ap, fmt);
	ptr = (char *)fmt;
	buff = NULL;
	buff = ft_sub_printf(ptr, &len, ap);
	if (buff)
	{
		ft_putnstr(buff, len);
		free(buff);
	}
	va_end(ap);
	return (len);
}

char	*ft_sub_printf(char *ptr, int *len, va_list ap)
{
	char	*buff;
	int		cur;

	buff = NULL;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			cur = ft_formatchk(ptr);
			if (cur > 0)
				buff = ft_appendfmt(buff, ptr + 1, len, ap);
			else
				return (ft_freemem(buff));
		}
		else
		{
			buff = ft_appendchr(buff, ptr, len);
			cur = 1;
		}
		ptr += cur;
	}
	return (buff);
}

char	*ft_appendfmt(char *buff, char *ptr, int *len, va_list ap)
{
	char			*new_buff;
	char			*pnt_buff;
	int				p_len;
	static t_prefix	t_pf;

	ft_freeprefix(&t_pf);
	p_len = *len;
	if (*(ptr) == '%')
		return (ft_appendchr(buff, ptr, len));
	ptr = ft_appendfmt2(ptr, &t_pf, ap);
	if (ft_specchk(ptr))
	{
		pnt_buff = ft_printf_spec(ptr, ap, len, &t_pf);
		if (!pnt_buff)
			return (ft_freemem(buff));
		new_buff = ft_mymemjoin(buff, pnt_buff, p_len, *len);
		free(buff);
		free(pnt_buff);
		if (!new_buff)
			return (ft_freemem(new_buff));
		return (new_buff);
	}
	free(buff);
	return (NULL);
}

char	*ft_appendfmt2(char *ptr, t_prefix *t_pf, va_list ap)
{
	while (!ft_specchk(ptr))
	{
		ptr += ft_is_left(ptr, t_pf);
		ptr += ft_is_sign(ptr, t_pf);
		ptr += ft_is_space(ptr, t_pf);
		ptr += ft_is_preceed(ptr, t_pf);
		ptr += ft_is_iszero(ptr, t_pf);
		ptr += ft_is_width(ptr, t_pf, ap);
		ptr += ft_is_precision(ptr, t_pf, ap);
	}
	return (ptr);
}

char	*ft_printf_spec(char *ptr, va_list ap, int *len, t_prefix *t_pf)
{
	char	*spec;

	spec = NULL;
	if (*ptr == 'c')
		spec = (ft_print_c(ap, len, t_pf));
	if (*ptr == 's')
		spec = (ft_print_s(ap, len));
	if (*ptr == 'd' || *ptr == 'i')
		spec = (ft_print_d(ap, len, t_pf));
	if (*ptr == 'p')
		spec = (ft_print_p(ap, len));
	if (*ptr == 'u')
		spec = (ft_print_u(ap, len));
	if (*ptr == 'x')
		spec = (ft_print_x(ap, 0, t_pf->is_preceed, len));
	if (*ptr == 'X')
		spec = (ft_print_x(ap, 1, t_pf->is_preceed, len));
	// spec = ft_format_spec(ptr, spec, len, t_pf);
	ft_freeprefix(t_pf);
	return (spec);
}
