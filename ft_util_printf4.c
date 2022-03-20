/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:19:25 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/20 02:24:12 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_iszero(char *ptr, t_prefix *t_pf)
{
	if (*ptr == '0')
	{
		t_pf->is_iszero = 1;
		return (1);
	}
	return (0);
}

int	ft_is_width(char *ptr, t_prefix *t_pf, va_list ap)
{
	if (*ptr == '*')
	{
		t_pf->width = va_arg(ap, size_t);
		return (1);
	}
	else if (*ptr >= '0' && *ptr <= '9')
	{
		return (ft_myatoi(ptr, t_pf, 0));
	}
	return (0);
}

int	ft_is_precision(char *ptr, t_prefix *t_pf, va_list ap)
{
	if (*ptr == '.')
	{
		ptr++;
		if (*ptr == '*')
		{
			t_pf->precision = va_arg(ap, size_t);
			return (2);
		}
		else if (*ptr >= '0' && *ptr <= '9')
		{
			return (ft_myatoi(ptr, t_pf, 0) + 1);
		}
		else if (ft_specchk(ptr))
		{
			t_pf->precision = 0;
			return (1);
		}
	}
	return (0);
}

char	*ft_append2str(char *buff, char c)
{
	size_t	buff_len;
	char	*new_buff;

	new_buff = NULL;
	if (buff)
		buff_len = ft_strlen(buff);
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
	*(new_buff + buff_len) = c;
	*(new_buff + buff_len + 1) = 0;
	return (new_buff);
}

char	*ft_append2str_ul(char *buff, char c, int shift)
{
	size_t	buff_len;
	char	*new_buff;

	if (shift)
	{
		if (c >= 'a' && c <= 'z')
			c -= 32;
	}
	new_buff = NULL;
	if (buff)
		buff_len = ft_strlen(buff);
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
	*(new_buff + buff_len) = c;
	*(new_buff + buff_len + 1) = 0;
	return (new_buff);
}
