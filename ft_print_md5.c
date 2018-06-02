/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_md5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:41:40 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/26 16:27:24 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_binary_md5(int i, t_flags *flags, t_md *hash)
{
	char	c;
	t_uchar *t;

	c = flags->c ? (char)':' : (char)' ';
	while (i < 4)
	{
		t = (t_uchar *)&hash->a;
		ft_printf("%.8b%c%.8b%c%.8b%c%.8b", t[0], c, t[1], c, t[2], c, t[3]);
		i < 3 ? ft_printf("%c", c) : 0;
		hash = hash->next;
		i++;
	}
}

void	ft_print_hash_md5(t_md *hash, t_flags *flags)
{
	t_uchar	*t;
	int		i;

	i = 0;
	if (!flags->b)
	{
		while (i < 4)
		{
			t = (t_uchar*)&hash->a;
			if (flags->c)
			{
				ft_printf("%.2x:%.2x:%.2x:%.2x", t[0], t[1], t[2], t[3]);
				i < 3 ? ft_printf(":") : 0;
			}
			else
				ft_printf("%.2x%.2x%.2x%.2x", t[0], t[1], t[2], t[3]);
			hash = hash->next;
			i++;
		}
	}
	else if (flags->b)
		ft_binary_md5(i, flags, hash);
	ft_del_md(hash);
}
