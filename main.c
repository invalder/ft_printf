/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:53:39 by nnakarac          #+#    #+#             */
/*   Updated: 2022/03/24 17:08:44 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		p_len;
	int		ft_len;

	p_len = printf("%10c", 0);
	// ft_len = ft_printf("f %-.4c \n", '9');
	printf("\np_len: %d\nft_len: %d\n", p_len, ft_len);
	return (0);
}
