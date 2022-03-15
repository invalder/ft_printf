/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:13:19 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/15 00:16:22 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
