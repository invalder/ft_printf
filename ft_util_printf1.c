/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 07:32:35 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/27 19:37:33 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_c(va_list ap, int *len, t_prefix *t_pf)
{
	char	*p_buff;

	p_buff = malloc(sizeof(char) * 2);
	if (!p_buff)
		return (NULL);
	*p_buff = (char) va_arg(ap, int);
	*(p_buff + 1) = 0;
	*len += 1;
	p_buff = ft_append_c(p_buff, t_pf, len);
	return (p_buff);
}

char	*ft_print_s(va_list ap, int *len, t_prefix *t_pf)
{
	char	*p_buff;
	char	*buff;
	char	*width_buff;
	size_t	buff_len;

	buff = va_arg(ap, char *);
	buff_len = ft_strlen(buff);
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
		buff_len = 6;
	}
	if (t_pf->is_precision && (size_t)t_pf->precision < buff_len)
		p_buff = ft_mysubstr(p_buff, 0, t_pf->precision);
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

char	*ft_print_d(va_list ap, int *len, t_prefix *t_pf)
{
	char	*p_buff;
	ssize_t	num;
	int		num_l;
	int		cur;
	int		neg;

	cur = 0;
	neg = 0;
	p_buff = NULL;
	num = va_arg(ap, int);
	if (num < 0)
		neg = 1;
	num_l = ft_nbrsize(num, 0);
	if (t_pf->is_sign || t_pf->is_space)
	{
		if (t_pf->is_sign && !neg)
			p_buff = ft_appendchr(p_buff, "+", &cur);
		else if (t_pf->is_space && !neg)
			p_buff = ft_appendchr(p_buff, " ", &cur);
	}
	if (t_pf->is_precision && t_pf->precision - num_l > 0)
	{
		while (t_pf->precision - num_l++)
			p_buff = ft_appendchr(p_buff, "0", &cur);
	}
	p_buff = ft_print_nbr(num, p_buff);
	p_buff = ft_append_d(p_buff, t_pf, ft_strlen(p_buff), num);
	if (p_buff)
		*len += ft_strlen(p_buff);
	return (p_buff);
}

char	*ft_print_nbr(ssize_t n, char *buff)
{
	ssize_t	num;

	num = n;
	if (num < 0)
		num *= -1;
	if (num < 10)
		buff = ft_append2str(buff, num + '0');
	else
	{
		buff = ft_print_nbr((num - (num % 10)) / 10, buff);
		buff = ft_print_nbr((num % 10), buff);
	}
	return (buff);
}
