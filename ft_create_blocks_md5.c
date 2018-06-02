/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_blocks_md5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 15:35:52 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/26 15:47:25 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

ssize_t			ft_find_size(ssize_t len)
{
	ssize_t size;

	size = len * 8 + 1;
	while (size % 512 != 448)
		size++;
	size = (size + 64) / 8;
	return (size);
}

t_uchar			*ft_alignment(ssize_t size, char *input)
{
	int		i;
	t_uchar	*res;

	res = (t_uchar*)malloc(sizeof(t_uchar) * (size));
	i = 0;
	while (i < size && input[i])
	{
		res[i] = (t_uchar)input[i];
		i++;
	}
	ft_strdel(&input);
	res[i++] = 0x80;
	while (i < size)
		res[i++] = 0;
	return (res);
}

t_uint			*ft_char2int_md5(t_uchar *bef, ssize_t newsize, ssize_t size)
{
	t_uint	*aft;
	int		i;

	i = 0;
	aft = (t_uint*)malloc(sizeof(t_uint) * newsize);
	while (i < newsize)
		aft[i++] = 0;
	size--;
	newsize--;
	while (newsize >= 0)
	{
		aft[newsize] = aft[newsize] | bef[size--] << 24;
		aft[newsize] = aft[newsize] | bef[size--] << 16;
		aft[newsize] = aft[newsize] | bef[size--] << 8;
		aft[newsize] = aft[newsize] | bef[size--] << 0;
		newsize--;
	}
	free(bef);
	return (aft);
}

t_uint			*ft_write_len_md5(ssize_t len, t_uint *data, ssize_t i)
{
	while (len)
	{
		data[i] = data[i] | (t_uint)len << 0;
		len = len >> 8;
		data[i] = data[i] | (t_uint)len << 8;
		len = len >> 8;
		data[i] = data[i] | (t_uint)len << 16;
		len = len >> 8;
		data[i] = data[i] | (t_uint)len << 24;
		len = len >> 8;
		i++;
	}
	return (data);
}
