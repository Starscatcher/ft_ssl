/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sha512.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:23:51 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/26 16:29:34 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_binary_sha512(t_flags *flags, t_ullint *hash, int i)
{
	char	c;
	t_uchar	*t;

	c = flags->c ? (char)':' : (char)' ';
	while (i < 8)
	{
		t = (t_uchar *)&hash[i];
		ft_printf("%.8b%c%.8b%c", t[7], c, t[6], c);
		ft_printf("%.8b%c%.8b%c", t[5], c, t[4], c);
		ft_printf("%.8b%c%.8b%c%.8b%c%.8b", t[3], c, t[2], c, t[1], c, t[0]);
		i < 7 ? ft_printf("%c", c) : 0;
		i++;
	}
}

void	ft_print_hash_512(t_ullint *hash, t_flags *flags)
{
	int		i;
	t_uchar	*t;

	i = 0;
	if (!flags->b)
	{
		while (i < 8)
		{
			t = (t_uchar *)&hash[i];
			if (flags->c)
			{
				ft_printf("%.2zx:%.2zx:%.2zx:%.2zx:", t[7], t[6], t[5], t[4]);
				ft_printf("%.2zx:%.2zx:%.2zx:%.2zx", t[3], t[2], t[1], t[0]);
				i < 7 ? ft_printf(":") : 0;
			}
			else
				ft_printf("%.16zx", hash[i]);
			i++;
		}
	}
	else if (flags->b)
		ft_binary_sha512(flags, hash, i);
	free(hash);
}
