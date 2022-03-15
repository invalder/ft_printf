/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:26:11 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/15 00:18:10 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <limits.h>

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
ssize_t	ft_formatchk(char *ptr);
size_t	ft_flgchk(char *ptr);
size_t	ft_widthchk(char *ptr);
size_t	ft_precisechk(char *ptr);
size_t	ft_isdigit(char c);
size_t	ft_nbrcnt(char *ptr);
size_t	ft_specchk(char *ptr);
char	*ft_appendchr(char *buff, char *ptr);
size_t	ft_strlen(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
