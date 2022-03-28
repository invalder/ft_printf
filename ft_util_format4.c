/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_format4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:19:25 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/28 23:26:19 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_iszero(char *ptr, t_prefix *t_pf)
{
	if (*ptr == '0')
	{
		t_pf->is_iszero = 1;
		return (1);
	}
	return (0);
}

int	ft_is_width(char *ptr, t_prefix *t_pf, va_list ap)
{
	if (*ptr == '*')
	{
		t_pf->width = va_arg(ap, size_t);
		return (1);
	}
	else if (*ptr >= '0' && *ptr <= '9')
	{
		return (ft_myatoi(ptr, t_pf, 0));
	}
	return (0);
}

int	ft_is_precision(char *ptr, t_prefix *t_pf, va_list ap)
{
	if (*ptr == '.')
	{
		t_pf->is_precision = 1;
		ptr++;
		if (*ptr == '*')
		{
			t_pf->precision = va_arg(ap, size_t);
			return (2);
		}
		else if (*ptr >= '0' && *ptr <= '9')
		{
			return (ft_myatoi(ptr, t_pf, 1) + 1);
		}
		else if (ft_specchk(ptr))
		{
			t_pf->precision = 0;
			return (1);
		}
	}
	return (0);
}
