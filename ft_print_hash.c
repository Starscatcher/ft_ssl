/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:23:51 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/02 17:13:40 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_print_hash_md5(t_md *hash)
{
	int				i;
	unsigned char	*tmp;

	i = 0;
	while (i < 4)
	{
		tmp = (unsigned char *)&hash->a;
		ft_printf("%.2x%.2x%.2x%.2x", tmp[0], tmp[1], tmp[2], tmp[3]);
		hash = hash->next;
		i++;
	}
	ft_del_md(hash);
}

void	ft_print_hash_224(t_uint *hash)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		ft_printf("%.8x", hash[i]);
		i++;
	}
	free(hash);
}

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

void	ft_print_hash_384(t_ullint *hash)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		ft_printf("%.16zx", hash[i]);
		i++;
	}
	free(hash);
}

void	ft_print_hash_512(t_ullint *hash)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_printf("%.16zx", hash[i]);
		i++;
	}
	free(hash);
}
