/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:53:39 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/16 20:46:53 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		p_len;
	int		ft_len;
	char	*buff;

	// buff = NULL;
	// buff = ft_print_nbru_b(1234567890, buff, 16, 0);
	//printf("buff: %s\n", buff);
	ft_printf("ftbuff: %d", 12345);

	//printf("testp: %p\n", buff);
	// p_len = printf("%-10c\n", 'c');
	// ft_len = ft_printf("%.2#d123456", 42);
	// ft_len = ft_printf("Hello World!");
	printf("\np_len: %d\nft_len: %d\n", p_len, ft_len);
	return (0);
}
