/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_blocks_sha512.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:26:03 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/26 16:11:01 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_ullint		ft_find_size_sha512(t_ullint len)
{
	t_ullint size;

	size = len * 8 + 1;
	while (size % 1024 != 896)
		size++;
	size = (size + 128) / 8;
	return (size);
}

t_uchar			*ft_alignment_sha512(t_ullint size, char *input)
{
	t_ullint	i;
	t_uchar		*res;

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

t_ullint		*ft_char2int_sha512(t_uchar *bef, ssize_t news, t_ullint s)
{
	t_ullint	*aft;
	int			i;
	t_ullint	temp;
	int			b;

	i = 0;
	aft = (t_ullint*)malloc(sizeof(t_ullint) * news);
	while (i < news)
		aft[i++] = 0;
	s--;
	news--;
	while (news >= 0)
	{
		b = 0;
		while (b < 64)
		{
			temp = bef[s--];
			aft[news] = aft[news] | temp << b;
			b += 8;
		}
		news--;
	}
	free(bef);
	return (aft);
}

t_ullint		*ft_write_len_sha512(t_ullint len, t_ullint *data, t_ullint i)
{
	data[i] = data[i] | len;
	return (data);
}
