/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:53:39 by nnakarac          #+#    #+#             */
/*   Updated: 2022/04/03 18:41:03 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		p_len;
	int		ft_len;
	// int		a = -4;

	// while (a < 5) //T34-69
	// {
		p_len = printf("p|%-2.4s|", NULL);
		ft_len = ft_printf("f|%-2.4s|", NULL);
		printf("\np_len: %d\nft_len: %d\n", p_len, ft_len);
	// 	a++;
	// }
	return (0);
}
