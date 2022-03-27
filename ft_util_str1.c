/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:50:42 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/26 15:02:01 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, size_t len)
{
	write(1, str, len);
}

size_t	ft_putstri(char *str)
{
	size_t	len;

	len = 0;
	if (str)
	{
		while (*(str + len))
		{
			ft_putchar(*(str + len));
			len++;
		}
	}
	else
		len = ft_putstri("(null)");
	return (len);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str)
	{
		while (*str++)
			len++;
	}
	return (len);
}

size_t	ft_myatoi(char *ptr, t_prefix *t_pf, int is_prec)
{
	size_t	len;
	int		num;

	len = 0;
	num = 0;
	while (*(ptr + len) != '.' && !ft_specchk(ptr + len))
	{
		num = (num * 10) + (*(ptr + len) - '0');
		len++;
	}
	if (is_prec)
		t_pf->precision = num;
	else
		t_pf->width = num;
	return (len);
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
