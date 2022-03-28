/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_format1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 03:00:26 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/28 23:27:22 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_appendfmt(char *buff, char *ptr, int *len, va_list ap)
{
	char			*new_buff;
	char			*p_buff;
	int				p_len;
	static t_prefix	t_pf;

	ft_freeprefix(&t_pf);
	p_len = *len;
	if (*(ptr) == '%')
		return (ft_appendchr(buff, ptr, len));
	ptr = ft_appendfmt2(ptr, &t_pf, ap);
	if (ft_specchk(ptr))
	{
		p_buff = ft_printf_spec(ptr, ap, len, &t_pf);
		if (!p_buff)
			return (ft_freemem(buff));
		new_buff = ft_mymemjoin(buff, p_buff, p_len, *len);
		free(buff);
		free(p_buff);
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

ssize_t	ft_formatchk(char *ptr)
{
	ssize_t	len;

	len = 1;
	if (*(ptr + len) == '%')
		return (2);
	while (!ft_specchk(ptr + len))
	{
		len += ft_flgchk(ptr + len);
		len += ft_widthchk(ptr + len);
		len += ft_precisechk(ptr + len);
	}
	if (ft_specchk(ptr + len))
		len += 1;
	else
		len = -1;
	return (len);
}
