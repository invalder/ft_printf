/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 07:32:35 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/25 11:00:20 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_c(va_list ap, int *len, t_prefix *t_pf)
{
	char	*pnt_buff;

	pnt_buff = malloc(sizeof(char) * 2);
	if (!pnt_buff)
		return (NULL);
	*pnt_buff = (char) va_arg(ap, int);
	*(pnt_buff + 1) = 0;
	*len += 1;
	pnt_buff = ft_appendwidth_c(pnt_buff, t_pf, len);
	return (pnt_buff);
}

char	*ft_print_s(va_list ap, int *len, t_prefix *t_pf)
{
	char	*pnt_buff;
	char	*buff;
	char	*width_buff;
	size_t	buff_len;

	buff = va_arg(ap, char *);
	buff_len = ft_strlen(buff);
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
	if (t_pf->is_precision && (size_t)t_pf->precision < buff_len)
		pnt_buff = ft_mysubstr(pnt_buff, 0, t_pf->precision);
	if ((size_t)t_pf->width > buff_len)
	{
		width_buff = ft_mycalloc(1, t_pf->width - buff_len + 1, ' ');
		if (t_pf->is_left)
			pnt_buff = ft_mystrjoin(pnt_buff, width_buff, 1, 1);
		else
			pnt_buff = ft_mystrjoin(width_buff, pnt_buff, 1, 1);
	}
	*len += ft_strlen(pnt_buff);
	return (pnt_buff);
}

char	*ft_print_d(va_list ap, int *len, t_prefix *t_pf)
{
	char	*pnt_buff;
	ssize_t	num;
	int 	num_l;
	int		cur;
	int		neg;

	cur = 0;
	neg = 0;
	pnt_buff = NULL;
	num = va_arg(ap, int);
	if (num < 0)
	{
		// num *= -1;
		neg = 1;
		// pnt_buff = ft_appendchr(pnt_buff, "-", &cur);
	}
	num_l = ft_nbrsize(num, 0);
	// if (num >= 0)
	// {
		if (t_pf->is_sign || t_pf->is_space)
		{
			if (t_pf->is_sign && !neg)
				pnt_buff = ft_appendchr(pnt_buff, "+", &cur);
			else if (t_pf->is_space && !neg)
				pnt_buff = ft_appendchr(pnt_buff, " ", &cur);
		}
		if (t_pf->is_precision && t_pf->precision - num_l > 0)
		{
			while (t_pf->precision - num_l++)
				pnt_buff = ft_appendchr(pnt_buff, "0", &cur);
		}
		//add width
		// pnt_buff = ft_appendwidth(pnt_buff, t_pf, num);
	// }
	pnt_buff = ft_print_nbr(num, pnt_buff);
	// add width and check alignment
	pnt_buff = ft_appendwidth_d(pnt_buff, t_pf, ft_strlen(pnt_buff), num);
	// if (neg)
	// 	pnt_buff = ft_mystrjoin("-", pnt_buff, 0, 1);
	if (pnt_buff)
		*len += ft_strlen(pnt_buff);
	return (pnt_buff);
}

char	*ft_print_nbr(ssize_t n, char *buff)
{
	// ssize_t	neg;
	ssize_t	num;

	// neg = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
		// neg = 1;
	}
	// if (neg)
	// 	buff = ft_append2str(buff, '-');
	if (num < 10)
		buff = ft_append2str(buff, num + '0');
	else
	{
		buff = ft_print_nbr((num - (num % 10)) / 10, buff);
		buff = ft_print_nbr((num % 10), buff);
	}
	return (buff);
}
