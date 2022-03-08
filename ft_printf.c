/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:09:35 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/09 01:02:06 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void	ft_putchar(char c);
void	ft_putnstr(char *str, size_t len);
int		ft_printf(const char *fmt, ...);
size_t	ft_nsignchk(const char *fmt);
size_t	ft_signchk(const char *fmt, va_list ap);
size_t	ft_putchari(char c);
size_t	ft_putstri(char *str);

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret_len;
	int		cur;
	int		len;
	char	*ptr;

	ret_len = 0;
	cur = 0;
	va_start(ap, fmt);
	ptr = (char *)fmt;
	while(*(ptr + cur))
	{
		len = ft_nsignchk(ptr + cur);
		if (len)
		{
			ft_putnstr(ptr + cur, len);
			cur += len;
		}
		else
		{
			len = ft_signchk(ptr + cur, ap);
			cur = cur + 2;
		}
	}
	va_end(ap);
	return (cur + 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnstr(char *str, size_t len)
{
	write(1, str, len);
}

size_t	ft_putchari(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstri(char *str)
{
	size_t	len;

	len = 0;
	while (*(str + len))
	{
		ft_putchar(*(str + len));
		len++;
	}
	return (len);
}

size_t	ft_nsignchk(const char *fmt)
{
	char	*ptr;
	size_t	len;

	len = 0;
	ptr = (char *)fmt;
	while (*ptr && *ptr != '%')
	{
		ptr++;
		len++;
	}
	return (len);
}

size_t	ft_signchk(const char *fmt, va_list ap)
{
	char	*ptr;
	size_t	len;

	len = 0;
	ptr = (char *)fmt;
	if (*ptr == '%')
		ptr++;
	if (*ptr == '%')
		len += ft_putchari('%');
	if (*ptr == ' ')
		len += ft_putchari(' ');
	if (*ptr == 's')
		len += ft_putstri(va_arg(ap, char *));
	return (len);
}

int	main(void)
{
	ft_printf("Hello World.\n%s\n", "12345");
}
