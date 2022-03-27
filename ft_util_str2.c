/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_str2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:03:28 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/26 15:04:29 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
