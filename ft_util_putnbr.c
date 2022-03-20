/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:52:33 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/20 02:37:57 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrsize(ssize_t n)
{
	ssize_t	neg;
	ssize_t	num;
	ssize_t	len;

	neg = 0;
	len = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
		neg = 1;
		len++;
	}
	if (num < 10)
		len++;
	else
	{
		len = ft_putnbr((num - (num % 10)) / 10, len);
		len = ft_putnbr((num % 10), len);
	}
	return (len);
}

size_t	ft_putnbr(ssize_t n, ssize_t len)
{
	ssize_t	neg;
	ssize_t	num;

	neg = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
		neg = 1;
		len++;
	}
	if (neg)
		ft_putchar('-');
	if (num < 10)
	{
		ft_putchar(num + '0');
		len++;
	}
	else
	{
		len = ft_putnbr((num - (num % 10)) / 10, len);
		len = ft_putnbr((num % 10), len);
	}
	return (len);
}

size_t	ft_putnbru_base(unsigned long long num, int b, int shift, ssize_t len)
{
	char	*base;

	base = ft_basenumber(b);
	if (b && num < (unsigned long long) b)
	{
		ft_putcharul(base[num], shift);
		len++;
	}
	else if (b && num >= (unsigned long long) b)
	{
		len = ft_putnbru_base((num / b), b, shift, len);
		len = ft_putnbru_base(num % b, b, shift, len);
	}
	free(base);
	return (len);
}

size_t	ft_nbrcnt(char *ptr)
{
	size_t	len;

	len = 0;
	while (ft_isdigit(*(ptr++)))
		len++;
	return (len);
}
