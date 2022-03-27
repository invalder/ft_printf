/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:04:58 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/26 15:12:03 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_append_x(char *p_buff, t_prefix *t_pf, int shift, unsigned int num)
{
	char	*ret_buff;
	char	*width_buff;
	size_t	len;
	char	append_c;
	int		sharp_l;

	append_c = ' ';
	sharp_l = 0;
	if (t_pf->is_preceed)
		sharp_l = 2;
	len = ft_strlen(p_buff);
	if (t_pf->is_iszero && !t_pf->is_precision)
		append_c = '0';
	if ((size_t)t_pf->width > len)
	{
		width_buff = ft_mycalloc(1, t_pf->width - len - sharp_l + 1, append_c);
		if (t_pf->is_left)
		{
			if (t_pf->is_preceed)
			{
				if (shift)
					p_buff = ft_mystrjoin("0X", p_buff, 0, 1);
				else
					p_buff = ft_mystrjoin("0x", p_buff, 0, 1);
			}
			ret_buff = ft_mystrjoin(p_buff, width_buff, 1, 1);
		}
		else
		{
			ret_buff = ft_mystrjoin(width_buff, p_buff, 1, 1);
			if (t_pf->is_preceed)
			{
				if (shift)
					ret_buff = ft_mystrjoin("0X", ret_buff, 0, 1);
				else
					ret_buff = ft_mystrjoin("0x", ret_buff, 0, 1);
			}
		}
		return (ret_buff);
	}
	else
	{
		if (t_pf->is_preceed && num > 0)
		{
			if (shift)
				p_buff = ft_mystrjoin("0X", p_buff, 0, 1);
			else
				p_buff = ft_mystrjoin("0x", p_buff, 0, 1);
		}
		return (p_buff);
	}
}
