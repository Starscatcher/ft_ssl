/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sha224.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:32:02 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/02 12:33:18 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_binary_sha224(int i, t_flags *flags, t_uint *hash)
{
	char	c;
	t_uchar	*t;

	c = flags->c ? (char)':' : (char)' ';
	while (i < 7)
	{
		t = (t_uchar*)&hash[i];
		ft_printf("%.8b%c%.8b%c%.8b%c%.8b", t[3], c, t[2], c, t[1], c, t[0]);
		i < 6 ? ft_printf("%c", c) : 0;
		i++;
	}
}

void	ft_print_hash_224(t_uint *hash, t_flags *flags)
{
	int		i;
	t_uchar	*t;

	i = 0;
	if (!flags->b)
	{
		while (i < 7)
		{
			t = (t_uchar*)&hash[i];
			if (flags->c)
			{
				ft_printf("%.2x:%.2x:%.2x:%.2x", t[3], t[2], t[1], t[0]);
				i < 6 ? ft_printf(":") : 0;
			}
			else
				ft_printf("%.8x", hash[i]);
			i++;
		}
	}
	else if (flags->b)
		ft_binary_sha224(i, flags, hash);
	free(hash);
}
