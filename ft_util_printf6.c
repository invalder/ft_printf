/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:28:13 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/28 02:09:40 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_append_d(char *p_buff, t_prefix *t_pf, size_t len, ssize_t num)
{
	int		neg;

	neg = 0;
	if (num < 0)
		neg = 1;
	if ((size_t)t_pf->width > len + neg)
	{
		return (ft_append_d_2(p_buff, t_pf, len, num));
	}
	else
	{
		if (neg)
			p_buff = ft_mystrjoin("-", p_buff, 0, 1);
		return (p_buff);
	}
}

char	*ft_append_d_2(char *p_buff, t_prefix *t_pf, size_t len, ssize_t num)
{
	char	*width_buff;
	char	*ret_buff;
	char	append_chr;
	int		neg;

	width_buff = NULL;
	ret_buff = NULL;
	append_chr = ' ';
	neg = 0;
	if (num < 0)
		neg = 1;
	if (t_pf->is_iszero && !t_pf->is_precision)
		append_chr = '0';
	if (neg && t_pf->is_precision)
		p_buff = ft_mystrjoin("-", p_buff, 0, 1);
	width_buff = ft_mycalloc(1, t_pf->width - (len + neg) + 1, append_chr);
	ret_buff = ft_append_d_3(p_buff, t_pf, width_buff, num);
	width_buff = NULL;
	return (ret_buff);
}

char	*ft_append_d_3(char *p_buff, t_prefix *t_pf, char *wbuff, ssize_t num)
{
	char	*ret_buff;
	char	append_chr;
	int		neg;

	append_chr = ' ';
	neg = 0;
	if (num < 0)
		neg = 1;
	if (t_pf->is_iszero && !t_pf->is_precision)
		append_chr = '0';
	if (t_pf->is_left)
	{
		ret_buff = ft_mystrjoin(p_buff, wbuff, 1, 1);
		if (neg && !t_pf->is_precision)
			ret_buff = ft_mystrjoin("-", ret_buff, 0, 1);
	}
	else
	{
		if (neg && !t_pf->is_precision && append_chr != '0')
			p_buff = ft_mystrjoin("-", p_buff, 0, 1);
		ret_buff = ft_mystrjoin(wbuff, p_buff, 1, 1);
		if (neg && append_chr == '0')
			ret_buff = ft_mystrjoin("-", ret_buff, 0, 1);
	}
	return (ret_buff);
}

char	*ft_append_c(char *p_buff, t_prefix *t_pf, int *len)
{
	char	*ret_buff;
	char	append_chr;

	ret_buff = NULL;
	append_chr = ' ';
	if ((size_t)t_pf->width > 1)
	{
		ret_buff = ft_mycalloc(1, t_pf->width + 1, append_chr);
		if (!ret_buff)
			return (NULL);
		if (t_pf->is_left)
		{
			ft_memcpy(ret_buff, p_buff, 1);
			free(p_buff);
		}
		else
		{
			ft_memcpy(ret_buff + t_pf->width - 1, p_buff, 1);
			free(p_buff);
		}
		*len += t_pf->width - 1;
		return (ret_buff);
	}
	else
		return (p_buff);
}

char	*ft_append_p(char *p_buff, t_prefix *t_pf)
{
	char	*ret_buff;
	char	*width_buff;
	size_t	len;

	len = ft_strlen(p_buff);
	if ((size_t)t_pf->width > len)
	{
		width_buff = ft_mycalloc(1, t_pf->width - len + 1, ' ');
		if (t_pf->is_left)
			ret_buff = ft_mystrjoin(p_buff, width_buff, 1, 1);
		else
			ret_buff = ft_mystrjoin(width_buff, p_buff, 1, 1);
		return (ret_buff);
	}
	else
	{
		return (p_buff);
	}
}

char	*ft_append_u(char *p_buff, t_prefix *t_pf)
{
	char	*ret_buff;
	char	*width_buff;
	size_t	len;
	char	append_chr;

	append_chr = ' ';
	len = ft_strlen(p_buff);
	if (t_pf->is_iszero && !t_pf->is_precision)
		append_chr = '0';
	if ((size_t)t_pf->width > len)
	{
		width_buff = ft_mycalloc(1, t_pf->width - len + 1, append_chr);
		if (t_pf->is_left)
			ret_buff = ft_mystrjoin(p_buff, width_buff, 1, 1);
		else
			ret_buff = ft_mystrjoin(width_buff, p_buff, 1, 1);
		return (ret_buff);
	}
	else
	{
		return (p_buff);
	}
}
