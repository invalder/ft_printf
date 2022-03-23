/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:53:39 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/24 01:49:16 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		p_len;
	int		ft_len;

	p_len = printf("p %-10.4d \n", 9);
	ft_len = ft_printf("f %-10.4d \n", 9);
	printf("\np_len: %d\nft_len: %d\n", p_len, ft_len);
	return (0);
}
