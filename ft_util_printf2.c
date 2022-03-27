/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:00:40 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/28 03:34:48 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

