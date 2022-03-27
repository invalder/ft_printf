/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:00:40 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/28 00:04:29 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_p(va_list ap, int *len, t_prefix *t_pf)
{
	char				*p_buff;
	unsigned long long	num;

	num = (unsigned long long)va_arg(ap, void *);
	p_buff = NULL;
	if (num)
	{
		p_buff = malloc(sizeof(char) * 3);
		if (!p_buff)
			return (NULL);
		ft_memcpy(p_buff, "0x", 3);
		p_buff = ft_print_nbru_b(num, p_buff, 16, 0);
	}
	else
	{
		p_buff = malloc(sizeof(char) * 4);
		if (!p_buff)
			return (NULL);
		ft_memcpy(p_buff, "0x0", 4);
	}
	p_buff = ft_append_p(p_buff, t_pf);
	if (p_buff)
		*len += ft_strlen(p_buff);
	return (p_buff);
}

char	*ft_print_nbru_b(unsigned long long num, char *buff, int b, int shift)
{
	char	*base;

	base = ft_basenumber(b);
	if (b && num < (unsigned long long) b)
		buff = ft_append2str_ul(buff, base[num], shift);
	else if (b && num >= (unsigned long long) b)
	{
		buff = ft_print_nbru_b((num / b), buff, b, shift);
		buff = ft_print_nbru_b(num % b, buff, b, shift);
	}
	free(base);
	return (buff);
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

char	*ft_print_u(va_list ap, int *len, t_prefix *t_pf)
{
	char			*p_buff;
	unsigned int	num;
	int				num_l;
	int				cur;

	cur = 0;
	num = (unsigned long long)va_arg(ap, void *);
	num_l = ft_nbrsize(num, 0);
	p_buff = NULL;
	if (t_pf->is_precision && t_pf->precision - num_l > 0)
	{
		while (t_pf->precision - num_l++)
			p_buff = ft_appendchr(p_buff, "0", &cur);
	}
	if (num == 0 && (t_pf->is_precision && t_pf->precision == 0))
		p_buff = ft_mystrjoin(p_buff, "", 1, 0);
	else
		p_buff = ft_print_nbru_b(num, p_buff, 10, 0);
	p_buff = ft_append_u(p_buff, t_pf);
	if (p_buff)
		*len += ft_strlen(p_buff);
	return (p_buff);
}

char	*ft_print_x(va_list ap, int is_shift, t_prefix *t_pf, int *len)
{
	char			*p_buff;
	unsigned int	num;
	int				num_l;
	int				cur;

	num = (unsigned long long)va_arg(ap, void *);
	num_l = ft_nbrusize_base(num, 0, 16);
	p_buff = NULL;
	cur = 0;
	if (t_pf->is_precision && t_pf->precision - num_l > 0)
	{
		while (t_pf->precision - num_l++)
			p_buff = ft_appendchr(p_buff, "0", &cur);
	}
	if (num == 0 && (t_pf->is_precision && t_pf->precision == 0))
		p_buff = ft_mystrjoin(p_buff, "", 1, 0);
	else
		p_buff = ft_print_nbru_b(num, p_buff, 16, is_shift);
	p_buff = ft_append_x(p_buff, t_pf, is_shift, num);
	if (p_buff)
		*len += ft_strlen(p_buff);
	return (p_buff);
}
