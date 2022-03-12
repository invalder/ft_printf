/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:09:35 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/12 19:58:06 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c);
void	ft_putnstr(char *str, size_t len);
int		ft_printf(const char *fmt, ...);
size_t	ft_nsignchk(const char *fmt);
size_t	ft_signchk(const char *fmt, va_list ap);
size_t	ft_putchari(char c);
size_t	ft_putstri(char *str);
size_t	ft_putcharul(char c, int shift);
size_t	ft_putnbr(ssize_t n, ssize_t len);
size_t	ft_putaddr_base(void *n, int base);
size_t	ft_putnbru_base(unsigned long long num, int b, int shift, ssize_t len);
char	*ft_basenumber(int base);

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		cur;
	int		len;
	int		len_res;
	char	*ptr;

	cur = 0;
	len_res = 0;
	va_start(ap, fmt);
	ptr = (char *)fmt;
	while(*(ptr + cur))
	{
		len = ft_nsignchk(ptr + cur);
		if (len)
		{
			ft_putnstr(ptr + cur, len);
			cur += len;
			len_res += len;
		}
		else
		{
			len = ft_signchk(ptr + cur, ap);
			cur = cur + 2;
			len_res += len;
		}
	}
	va_end(ap);
	return (len_res);
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

size_t	ft_putcharul(char c, int shift)
{
	if (shift && (c >= 'a' && c <= 'z'))
		c -= 32;
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstri(char *str)
{
	size_t	len;

	len = 0;
	if(str)
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
	if (*ptr == 'c')
		len += ft_putchari(va_arg(ap, int));
	if (*ptr == 's')
		len += ft_putstri(va_arg(ap, char *));
	if (*ptr == 'd' || *ptr == 'i')
		len += ft_putnbr(va_arg(ap, int), 0);
	if (*ptr == 'p')
		len += ft_putaddr_base(va_arg(ap, void *), 16);
	if (*ptr == 'u')
		len += ft_putnbru_base(va_arg(ap, unsigned int), 10, 0, 0);
	if (*ptr == 'o')
		len += ft_putnbru_base(va_arg(ap, unsigned int), 8, 0, 0);
	if (*ptr == 'x')
		len += ft_putnbru_base(va_arg(ap, unsigned int), 16, 0, 0);
	if (*ptr == 'X')
		len += ft_putnbru_base(va_arg(ap, unsigned int), 16, 1, 0);
	return (len);
}

size_t	ft_putnbr(ssize_t n, ssize_t len)
{
	ssize_t	neg;
	ssize_t	num;

	neg = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
		neg = 1;
		len++;
	}
	if (neg)
		ft_putchar('-');
	if (num < 10)
	{
		ft_putchar(num + '0');
		len++;
	}
	else
	{
		len = ft_putnbr((num - (num % 10)) / 10, len);
		len = ft_putnbr((num % 10), len);
	}
	return (len);
}

size_t	ft_putaddr_base(void *n, int base)
{
	unsigned long long	num;
	size_t				len;

	num = (unsigned long long) n;
	if (num)
	{
		len = ft_putstri("0x");
		len += ft_putnbru_base(num, base, 0, 0);
	}
	else
	{
		len = ft_putstri("(nil)");
	}
	return (len);
}

size_t	ft_putnbru_base(unsigned long long num, int b, int shift, ssize_t len)
{
	char	*base;

	base = ft_basenumber(b);
	if (b && num < (unsigned long long) b)
	{
		ft_putcharul(base[num], shift);
		len++;
	}
	else if (b && num >= (unsigned long long) b)
	{
		len = ft_putnbru_base((num / b), b, shift, len);
		len = ft_putnbru_base(num % b, b, shift, len);
	}
	free(base);
	return (len);
}

char	*ft_basenumber(int base)
{
	char	*bres;

	bres = malloc(sizeof(char) * 17);
	if (!bres)
		return (NULL);
	if (base == 2)
		strncpy(bres, "01", 3);
	else if (base == 10)
		strncpy(bres, "0123456789", 11);
	else if (base == 16)
		strncpy(bres, "0123456789abcdef", 17);
	else
		strncpy(bres, "", 2);
	return (bres);
}
