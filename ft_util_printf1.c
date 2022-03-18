/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 07:32:35 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/18 23:00:43 by nnakarac         ###   ########.fr       */
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

	buff = va_arg(ap, char*);
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

char	*ft_print_d(va_list ap, int *len)
{
	char	*pnt_buff;

	pnt_buff = NULL;
	pnt_buff = ft_print_nbr(va_arg(ap, int), pnt_buff);
	// printf("ft_print_d: %s\n", pnt_buff);
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

char	*ft_print_p(va_list ap, int *len)
{
	char				*pnt_buff;
	unsigned long long	num;

	num = (unsigned long long)va_arg(ap, void *);
	pnt_buff = NULL;
	if (num)
	{
		pnt_buff = malloc(sizeof(char) * 3);
		if (!pnt_buff)
			return (NULL);
		ft_memcpy(pnt_buff, "0x", 3);
		pnt_buff = ft_print_nbru_b(num, pnt_buff, 16, 0);
	}
	else
	{
		pnt_buff = malloc(sizeof(char) * 4);
		if (!pnt_buff)
			return (NULL);
		ft_memcpy(pnt_buff, "0x0", 4);
	}
	if (pnt_buff)
		*len += ft_strlen(pnt_buff);
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

char	*ft_print_u(va_list ap, int *len)
{
	char			*pnt_buff;
	unsigned int	num;

	num = (unsigned long long)va_arg(ap, void *);
	pnt_buff = NULL;
	pnt_buff = ft_print_nbru_b(num, pnt_buff, 10, 0);
	if (pnt_buff)
		*len += ft_strlen(pnt_buff);
	return (pnt_buff);
}

char	*ft_print_x(va_list ap, int is_shift, int is_sharp, int *len)
{
	char	*pnt_buff;
	unsigned int	num;

	num = (unsigned long long)va_arg(ap, void *);
	pnt_buff = NULL;
	if (is_sharp)
	{
		pnt_buff = malloc(sizeof(char) * 3);
		if (pnt_buff)
			return (NULL);
		if (is_shift)
			ft_memcpy(pnt_buff, "0x", 3);
		else
			ft_memcpy(pnt_buff, "0X", 3);
	}
	pnt_buff = ft_print_nbru_b(num, pnt_buff, 16, is_shift);
	if (pnt_buff)
		*len += ft_strlen(pnt_buff);
	return (pnt_buff);
}
