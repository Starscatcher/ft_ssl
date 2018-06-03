/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sha256.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:21:38 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/02 17:13:40 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_print_hash_256(t_uint *hash)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_printf("%.8x", hash[i]);
		i++;
	}
	free(hash);
}
