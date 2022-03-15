/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 07:32:35 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/16 01:55:23 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_c(va_list ap)
{
	char	*pnt_buff;

	pnt_buff = malloc(sizeof(char) * 2);
	if (!pnt_buff)
		return (NULL);
	*pnt_buff = (char) va_arg(ap, int);
	*(pnt_buff + 1) = 0;
	return (pnt_buff);
}

char	*ft_print_s(va_list ap)
{
	char	*pnt_buff;
	char	*buff;

	buff = va_arg(ap, char*);
	pnt_buff = malloc(sizeof(char) * (ft_strlen(buff) + 1));
	ft_memcpy(pnt_buff, buff, (ft_strlen(buff) + 1));
	return (pnt_buff);
}

char	*ft_print_d(va_list ap)
{
	char	*pnt_buff;

	pnt_buff = NULL;
	pnt_buff = ft_print_nbr(va_arg(ap, int), pnt_buff);
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

char	*ft_print_addr(va_list ap)
{
	char	*pnt_buff;

	pnt_buff = NULL;
	pnt_buff = malloc(sizeof(char) * 3);
	if (pnt_buff)
		return (NULL);
	ft_memcpy(pnt_buff, "0x", 3);
	pnt_buff = ft_print_nbru_b((unsigned long long)va_arg(ap, void *), pnt_buff, 16, 0);
	return (pnt_buff);
}

char	*ft_print_nbru_b(unsigned long long num, char *buff, int b, int shift)
{
	char	*base;

	base = ft_basenumber(b);
	if (b && num < (unsigned long long) b)
		buff = ft_append2str_ul(buff, base[num], shift);
	else if (b && num >= (unsigned long long) b)
	{
		buff = ft_print_nbru_b((num / b), buff, b, shift);
		buff = ft_print_nbru_b(num % b, buff, b, shift);
	}
	free(base);
	return (buff);
}

char	*ft_basenumber(int base)
{
	char	*bres;

	bres = malloc(sizeof(char) * 17);
	if (!bres)
		return (NULL);
	if (base == 2)
		strncpy(bres, "01", 3);
	else if (base == 10)
		strncpy(bres, "0123456789", 11);
	else if (base == 16)
		strncpy(bres, "0123456789abcdef", 17);
	else
		strncpy(bres, "", 2);
	return (bres);
}

char	*ft_print_u(va_list ap)
{
	char	*pnt_buff;

	pnt_buff = NULL;
	if (pnt_buff)
		return (NULL);
	ft_memcpy(pnt_buff, "0x", 3);
	pnt_buff = ft_print_nbru_b((unsigned long long)va_arg(ap, void *), pnt_buff, 16, 0);
	return (pnt_buff);
}

char	*ft_print_x(va_list ap, int is_shift, int is_sharp)
{
	char	*pnt_buff;

	pnt_buff = NULL;
	if (pnt_buff)
		return (NULL);
	ft_memcpy(pnt_buff, "0x", 3);
	pnt_buff = ft_print_nbru_b((unsigned long long)va_arg(ap, void *), pnt_buff, 16, is_shift);
	return (pnt_buff);
}
