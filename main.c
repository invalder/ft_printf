/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:53:39 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/12 19:58:46 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int p_len;
	int ft_len;
	// char	test[12] = "Hello World";

	// ft_printf("Hello World.\n%s\n%d\n%p\n%u\n%x\n%x\n", "12345", 1234567890, &test, 1234567890, -255, -255);
	// printf("addr p: %p\n", &test);
	// printf("addr ld: %ld\n", (long) &test);
	// printf("-255: %x\n", -255);
	// // printf("-1 p : %p\n", -1);
	// p_len = printf("%s %s", "YES", "NO");
	// ft_len = ft_printf("%s %s", "YES", "NO");
	// p_len = printf(" %X ", LONG_MAX);
	// p_len = printf("%s", NULL);
	p_len = printf("%o", -1);
	ft_len = printf("%o", -1);
	// ft_len = ft_printf(" %X ", LONG_MAX);

	printf("\np_len: %d\nft_len: %d\n", p_len, ft_len);


	return (0);
}
