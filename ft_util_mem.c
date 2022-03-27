/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:13:19 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/26 15:01:27 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_d;
	const unsigned char	*ptr_s;

	ptr_d = dest;
	ptr_s = src;
	if (dest == NULL || src == NULL)
	{
		if (dest == NULL)
			return (NULL);
		return (dest);
	}
	if (n)
		while (n-- > 0)
			*ptr_d++ = *ptr_s++;
	return (dest);
}

char	*ft_freemem(char *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

char	*ft_mymemjoin(char *s1, char *s2, size_t len1, size_t len_t)
{
	char	*new_buff;

	new_buff = malloc(sizeof(char) * (len_t + 1));
	if (!new_buff)
		return (NULL);
	ft_memcpy(new_buff, s1, len1);
	ft_memcpy(new_buff + len1, s2, len_t - len1);
	*(new_buff + len_t) = 0;
	return (new_buff);
}
