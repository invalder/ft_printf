/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_chk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:59:27 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/14 17:30:39 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_flgchk(char *ptr)
{
	if (*ptr == '-' || *ptr == '+' || *ptr == ' ' || *ptr == '#' || *ptr == '0')
		return (1);
	return (0);
}

size_t	ft_widthchk(char *ptr)
{
	if (*ptr == '*')
		return (1);
	if (ft_isdigit)
}

