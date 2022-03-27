/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_print_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 03:11:46 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/28 03:12:18 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_s(va_list ap, int *len, t_prefix *t_pf)
{
	char	*p_buff;
	char	*buff;
	char	*width_buff;
	size_t	buff_len;

	buff = va_arg(ap, char *);
	buff_len = ft_strlen(buff);
	p_buff = ft_print_s2(buff);
	buff_len = ft_strlen(p_buff);
	if (t_pf->is_precision && (size_t)t_pf->precision < buff_len)
		p_buff = ft_mysubstr(p_buff, 0, t_pf->precision);
	buff_len = ft_strlen(p_buff);
	if ((size_t)t_pf->width > buff_len)
	{
		width_buff = ft_mycalloc(1, t_pf->width - buff_len + 1, ' ');
		if (!width_buff)
			return (NULL);
		if (t_pf->is_left)
			p_buff = ft_mystrjoin(p_buff, width_buff, 1, 1);
		else
			p_buff = ft_mystrjoin(width_buff, p_buff, 1, 1);
	}
	*len += ft_strlen(p_buff);
	return (p_buff);
}

char	*ft_print_s2(char *buff)
{
	char	*p_buff;

	if (buff)
	{
		p_buff = malloc(sizeof(char) * (ft_strlen(buff) + 1));
		if (!p_buff)
			return (NULL);
		ft_memcpy(p_buff, buff, (ft_strlen(buff) + 1));
	}
	else
	{
		p_buff = malloc(sizeof(char) * 7);
		if (!p_buff)
			return (NULL);
		ft_memcpy(p_buff, "(null)", 7);
	}
	return (p_buff);
}
