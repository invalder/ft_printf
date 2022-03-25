/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:28:13 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/26 03:58:26 by nnakarac         ###   ########.fr       */
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

char	*ft_appendwidth_d(char *pnt_buff, t_prefix *t_pf, size_t len, ssize_t num)
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
	if (t_pf->is_iszero && !t_pf->is_precision)
		append_chr = '0';
	if ((size_t)t_pf->width > len + neg)
	{
		// printf("Here1\n");
		if (neg && t_pf->is_precision)
			pnt_buff = ft_mystrjoin("-", pnt_buff, 0, 1);
		width_buff = ft_mycalloc(1, t_pf->width - (len + neg) + 1, append_chr);
		if (t_pf->is_left)
			ret_buff = ft_mystrjoin(pnt_buff, width_buff, 1, 1);
		else
			ret_buff = ft_mystrjoin(width_buff, pnt_buff, 1, 1);
		if (neg && !t_pf->is_precision)
			ret_buff = ft_mystrjoin("-", ret_buff, 0, 1);
		return (ret_buff);
	}
	else
	{
		// printf("Here2\n");
		if (neg)
			pnt_buff = ft_mystrjoin("-", pnt_buff, 0, 1);
		return (pnt_buff);
	}
}

char	*ft_appendwidth_c(char *pnt_buff, t_prefix *t_pf, int *len)
{
	char	*ret_buff;
	char	append_chr;

	ret_buff = NULL;
	append_chr = ' ';
	if ((size_t)t_pf->width > 1)
	{
		ret_buff = ft_mycalloc(1, t_pf->width + 1, append_chr);
		if (t_pf->is_left)
		{
			ft_memcpy(ret_buff, pnt_buff, 1);
			free(pnt_buff);
		}
		else
		{
			ft_memcpy(ret_buff + t_pf->width - 1, pnt_buff, 1);
			free(pnt_buff);
		}
		*len += t_pf->width - 1;
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

char	*ft_mysubstr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	m_len;

	s_len = (unsigned int)ft_strlen(s);
	if ((start + len) > s_len && (start + 1) <= s_len)
		m_len = s_len - start;
	else if ((start + 1) > s_len)
		m_len = 0;
	else
		m_len = len;
	substr = (char *)malloc(sizeof(char) * (m_len + 1));
	if (!substr)
	{
		free(s);
		return (NULL);
	}
	if (m_len != 0)
		m_len = ft_strlcpy(substr, &s[start], (m_len + 1));
	else
		*substr = '\0';
	free(s);
	return (substr);
}

size_t	ft_strlcpy(char *dst, char *src, size_t maxlen)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < maxlen)
		ft_memcpy(dst, src, src_len + 1);
	else if (maxlen > 0)
	{
		ft_memcpy(dst, src, maxlen - 1);
		dst[maxlen - 1] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_appendwidth_p(char *pnt_buff, t_prefix *t_pf)
{
	char	*ret_buff;
	char	*width_buff;
	size_t	len;

	len = ft_strlen(pnt_buff);
	if ((size_t)t_pf->width > len)
	{
		width_buff = ft_mycalloc(1, t_pf->width - len + 1, ' ');
		if (t_pf->is_left)
			ret_buff = ft_mystrjoin(pnt_buff, width_buff, 1, 1);
		else
			ret_buff = ft_mystrjoin(width_buff, pnt_buff, 1, 1);
		return (ret_buff);
	}
	else
	{
		return (pnt_buff);
	}
}

char	*ft_appendwidth_u(char *pnt_buff, t_prefix *t_pf)
{
	char	*ret_buff;
	char	*width_buff;
	size_t	len;
	char	append_chr;

	append_chr = ' ';
	len = ft_strlen(pnt_buff);
	if (t_pf->is_iszero && !t_pf->is_precision)
		append_chr = '0';
	if ((size_t)t_pf->width > len)
	{
		width_buff = ft_mycalloc(1, t_pf->width - len + 1, append_chr);
		if (t_pf->is_left)
			ret_buff = ft_mystrjoin(pnt_buff, width_buff, 1, 1);
		else
			ret_buff = ft_mystrjoin(width_buff, pnt_buff, 1, 1);
		return (ret_buff);
	}
	else
	{
		return (pnt_buff);
	}
}

char	*ft_appendwidth_x(char *pnt_buff, t_prefix *t_pf, int is_shift, unsigned int num)
{
	char	*ret_buff;
	char	*width_buff;
	size_t	len;
	char	append_chr;
	int		shift;

	append_chr = ' ';
	shift = 0;
	if (t_pf->is_preceed)
		shift = 2;
	len = ft_strlen(pnt_buff);
	if (t_pf->is_iszero && !t_pf->is_precision)
		append_chr = '0';
	if ((size_t)t_pf->width > len)
	{
		width_buff = ft_mycalloc(1, t_pf->width - len - shift + 1, append_chr);
		if (t_pf->is_left)
		{
			if (t_pf->is_preceed)
			{
				if (is_shift)
					pnt_buff = ft_mystrjoin("0X", pnt_buff, 0, 1);
				else
					pnt_buff = ft_mystrjoin("0x", pnt_buff, 0, 1);
			}
			ret_buff = ft_mystrjoin(pnt_buff, width_buff, 1, 1);
		}
		else
		{
			ret_buff = ft_mystrjoin(width_buff, pnt_buff, 1, 1);
			if (t_pf->is_preceed)
			{
				if (is_shift)
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
			if (is_shift)
				pnt_buff = ft_mystrjoin("0X", pnt_buff, 0, 1);
			else
				pnt_buff = ft_mystrjoin("0x", pnt_buff, 0, 1);
		}
		return (pnt_buff);
	}
}
