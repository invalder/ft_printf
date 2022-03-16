/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:26:11 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/16 20:00:56 by nnakarac         ###   ########.fr       */
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
char	*ft_append2str(char *buff, char c);
size_t	ft_strlen(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_print_nbr(ssize_t n, char *buff);
char	*ft_append2str_ul(char *buff, char c, int shift);
char	*ft_print_addr(va_list ap);
char	*ft_print_nbru_b(unsigned long long num, char *buff, int b, int shift);
char	*ft_basenumber(int base);

char	*ft_print_c(va_list ap);
char	*ft_print_s(va_list ap);
char	*ft_print_d(va_list ap);
char	*ft_print_p(va_list ap);
char	*ft_print_u(va_list ap);
char	*ft_print_x(va_list ap, int is_shift, int is_sharp);

char	*ft_printf_spec(char *ptr, va_list ap);
char	*ft_appendfmt(char *buff, char *ptr, size_t cur, va_list ap);



typedef struct s_prefix
{
	int		is_left;
	int		is_sign;
	int		is_space;
	int		is_preceed;
	int		is_iszero;
	int		width;
	int		precision;
}	t_prefix;


#endif
