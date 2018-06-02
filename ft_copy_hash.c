/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:03:37 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/26 16:09:59 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_ullint	*ft_copy_hash_512(t_ullint *hash)
{
	int			i;
	t_ullint	*tmp;

	i = 0;
	tmp = (t_ullint*)malloc(sizeof(t_ullint) * 8);
	while (i < 8)
	{
		tmp[i] = hash[i];
		i++;
	}
	return (tmp);
}

t_uint		*ft_copy_hash(t_uint *hash)
{
	int		i;
	t_uint	*tmp;

	i = 0;
	tmp = (unsigned int*)malloc(sizeof(unsigned int) * 8);
	while (i < 8)
	{
		tmp[i] = hash[i];
		i++;
	}
	return (tmp);
}
