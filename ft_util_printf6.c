/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:28:13 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/24 02:19:14 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char	*ft_format_spec(char *ptr, char *spec, int *len, t_prefix *t_pf)
// {
// 	int	s_len;

// 	// if (*ptr != 'c')
// 	// 	s_len = ft_strlen(spec);
// 	// else
// 	// 	s_len = 1;
// 	// //zero (for padding need width to be specidied)

// 	// //width
// 	// if (t_pf->width > 0)
// 	// {

// 	// }

// 	//precision

// 	//munis -> left justified

// 	return (spec);
// }

char	*ft_appendwidth(char *pnt_buff, t_prefix *t_pf, size_t len, ssize_t num)
{
	char	*width_buff;
	char	*ret_buff;
	char	append_chr;
	int		neg;

	width_buff = NULL;
	append_chr = ' ';
	neg = 0;
	if (num < 0)
		neg = 1;
	if (t_pf->is_iszero)
		append_chr = '0';
	if ((size_t)t_pf->width > len + neg)
	{
		width_buff = ft_mycalloc(1, t_pf->width - (len + neg) + 1, append_chr);
		if (t_pf->is_left)
			ret_buff = ft_mystrjoin(pnt_buff, width_buff, 1, 1);
		else
			ret_buff = ft_mystrjoin(width_buff, pnt_buff, 1, 1);
		return (ret_buff);
	}
	else
		return (pnt_buff);
}

char	*ft_mycalloc(size_t size, size_t len, char c)
{
	char	*buff;
	size_t	cnt;

	cnt = 0;
	if (len && size)
	{
		buff = malloc(size * len);
		if (!buff)
			return (NULL);
		while (cnt < len)
		{
			*(buff + cnt++) = c;
		}
		*(buff + cnt - 1) = 0;
		return (buff);
	}
	return (NULL);
}

char	*ft_mystrjoin(char *s1, char *s2, int free_s1, int free_s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str)
	{
		ft_memcpy(str, s1, s1_len);
		ft_memcpy(str + s1_len, s2, s2_len + 1);
	}
	else
	{
		if (free_s1)
			ft_freemem(s1);
		if (free_s2)
			ft_freemem(s2);
		return (NULL);
	}
	if (free_s1)
		ft_freemem(s1);
	if (free_s2)
		ft_freemem(s2);
	return (str);
}
