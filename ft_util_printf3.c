/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:17:12 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/20 02:18:10 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_freeprefix(t_prefix *t_pf)
{
	t_pf->is_left = 0;
	t_pf->is_sign = 0;
	t_pf->is_space = 0;
	t_pf->is_preceed = 0;
	t_pf->is_iszero = 0;
	t_pf->width = 0;
	t_pf->precision = 0;
}

int	ft_is_left(char *ptr, t_prefix *t_pf)
{
	if (*ptr == '-')
	{
		t_pf->is_left = 1;
		return (1);
	}
	return (0);
}

int	ft_is_sign(char *ptr, t_prefix *t_pf)
{
	if (*ptr == '+')
	{
		t_pf->is_sign = 1;
		return (1);
	}
	return (0);
}

int	ft_is_space(char *ptr, t_prefix *t_pf)
{
	if (*ptr == ' ')
	{
		t_pf->is_space = 1;
		return (1);
	}
	return (0);
}

int	ft_is_preceed(char *ptr, t_prefix *t_pf)
{
	if (*ptr == '#')
	{
		t_pf->is_preceed = 1;
		return (1);
	}
	return (0);
}
