/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 07:32:35 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/28 03:15:37 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
