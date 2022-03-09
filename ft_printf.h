/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:26:11 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/10 02:24:47 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

void	ft_putchar(char c);
void	ft_putnstr(char *str, size_t len);
int		ft_printf(const char *fmt, ...);
size_t	ft_nsignchk(const char *fmt);
size_t	ft_signchk(const char *fmt, va_list ap);
size_t	ft_putchari(char c);
size_t	ft_putstri(char *str);
size_t	ft_putnbr(ssize_t n, ssize_t len);
size_t	ft_putaddr_base(void *n, int base);
size_t	ft_putnbru_base(unsigned long long num, int b);
char	*ft_basenumber(int base);

#endif
