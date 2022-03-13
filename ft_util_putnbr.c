/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:52:33 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/13 13:08:03 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
