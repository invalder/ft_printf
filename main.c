/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:53:39 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/10 03:29:41 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	test[12] = "Hello World";

	ft_printf("Hello World.\n%s\n%d\n%p\n%u\n%x\n", "12345", 1234567890, &test, 1234567890, -255);
	printf("addr p: %p\n", &test);
	printf("addr ld: %ld\n", (long) &test);
	printf("-255: %x\n", -255);
	return (0);
}
