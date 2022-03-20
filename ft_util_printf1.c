/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 07:32:35 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/20 14:56:11 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_c(va_list ap, int *len)
{
	char	*pnt_buff;

	pnt_buff = malloc(sizeof(char) * 2);
	if (!pnt_buff)
		return (NULL);
	*pnt_buff = (char) va_arg(ap, int);
	*(pnt_buff + 1) = 0;
	*len += 1;
	return (pnt_buff);
}

char	*ft_print_s(va_list ap, int *len)
{
	char	*pnt_buff;
	char	*buff;

	buff = va_arg(ap, char *);
	if (buff)
	{
		pnt_buff = malloc(sizeof(char) * (ft_strlen(buff) + 1));
		ft_memcpy(pnt_buff, buff, (ft_strlen(buff) + 1));
	}
	else
	{
		pnt_buff = malloc(sizeof(char) * 7);
		if (!pnt_buff)
			return (NULL);
		ft_memcpy(pnt_buff, "(null)", 7);
	}
	*len += ft_strlen(pnt_buff);
	return (pnt_buff);
}

char	*ft_print_d(va_list ap, int *len, t_prefix *t_pf)
{
	char	*pnt_buff;
	int		num;

	pnt_buff = NULL;
	num = va_arg(ap, int);
	if (num >= 0)
	{
		if (t_pf->is_sign || t_pf->is_space)
		{
			pnt_buff = malloc(sizeof(char) * 2);
			if (!pnt_buff)
				return (NULL);
			if (t_pf->is_sign)
				ft_memcpy(pnt_buff, "+", 2);
			if (t_pf->is_space)
				ft_memcpy(pnt_buff, "+", 2);
		}
	}
	pnt_buff = ft_print_nbr(num, pnt_buff);
	if (pnt_buff)
		*len += ft_strlen(pnt_buff);
	return (pnt_buff);
}

char	*ft_print_nbr(ssize_t n, char *buff)
{
	ssize_t	neg;
	ssize_t	num;

	neg = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
		neg = 1;
	}
	if (neg)
		buff = ft_append2str(buff, '-');
	if (num < 10)
		buff = ft_append2str(buff, num + '0');
	else
	{
		buff = ft_print_nbr((num - (num % 10)) / 10, buff);
		buff = ft_print_nbr((num % 10), buff);
	}
	return (buff);
}
