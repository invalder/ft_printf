/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:22:29 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/20 02:24:32 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_formatchk(char *ptr)
{
	ssize_t	len;

	len = 1;
	if (*(ptr + len) == '%')
		return (2);
	while (!ft_specchk(ptr + len))
	{
		len += ft_flgchk(ptr + len);
		len += ft_widthchk(ptr + len);
		len += ft_precisechk(ptr + len);
	}
	if (ft_specchk(ptr + len))
		len += 1;
	else
		len = -1;
	return (len);
}

char	*ft_appendchr(char *buff, char *ptr, int *len)
{
	size_t	buff_len;
	char	*new_buff;

	new_buff = NULL;
	if (buff)
		buff_len = *len;
	else
		buff_len = 0;
	new_buff = malloc(sizeof(char) * (buff_len + 2));
	if (!new_buff)
		return (NULL);
	if (buff)
	{
		ft_memcpy(new_buff, buff, buff_len);
		free(buff);
	}
	ft_memcpy(new_buff + buff_len, ptr, 1);
	*(new_buff + buff_len + 1) = 0;
	*len += 1;
	return (new_buff);
}
