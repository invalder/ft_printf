/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:04:58 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/28 02:21:43 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_append_x(char *p_buff, t_prefix *t_pf, int up, unsigned int n)
{
	size_t	len;

	len = ft_strlen(p_buff);
	if ((size_t)t_pf->width > len)
	{
		return (ft_append_x_2(p_buff, t_pf, up, n));
	}
	else
		return (ft_append_zx(p_buff, t_pf, up, n));
}

char	*ft_append_x_2(char *p_buff, t_prefix *t_pf, int up, unsigned int n)
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
	width_buff = ft_mycalloc(1, t_pf->width - len - sharp_l + 1, append_c);
	if (t_pf->is_left)
	{
		p_buff = ft_append_zx(p_buff, t_pf, up, n);
		ret_buff = ft_mystrjoin(p_buff, width_buff, 1, 1);
	}
	else
	{
		ret_buff = ft_mystrjoin(width_buff, p_buff, 1, 1);
		ret_buff = ft_append_zx(ret_buff, t_pf, up, n);
	}
	return (ret_buff);
}

char	*ft_append_zx(char *buff, t_prefix *t_pf, int up, unsigned int num)
{
	if (t_pf->is_preceed && num > 0)
	{
		if (up)
			buff = ft_mystrjoin("0X", buff, 0, 1);
		else
			buff = ft_mystrjoin("0x", buff, 0, 1);
	}
	return (buff);
}
