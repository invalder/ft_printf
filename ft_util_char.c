/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:44:12 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/13 11:46:00 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_putchari(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putcharul(char c, int shift)
{
	if (shift && (c >= 'a' && c <= 'z'))
		c -= 32;
	write(1, &c, 1);
	return (1);
}
