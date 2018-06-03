/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:38:30 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/03 18:04:57 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_md5_flag(size_t len, char *input, t_flags *flags)
{
	ssize_t	size;
	t_uchar	*newinp;
	t_uint	*arr;
	t_md	*hash;

	flags->md5++;
	size = ft_find_size(len);
	newinp = ft_alignment(size, input);
	hash = ft_create_md(NULL);
	ft_initialize_buff_md5(hash);
	arr = ft_char2int_md5(newinp, size / 4, size);
	arr = ft_write_len_md5((len * 8), arr, ((size / 4) - 2));
	ft_alg_md5(hash, size, arr);
	ft_print_hash_md5(hash);
}

void	ft_sha256_flag(size_t len, char *input, t_flags *flags)
{
	ssize_t	size;
	t_uchar	*newinp;
	t_uint	*arr;
	t_uint	*hash;

	size = ft_find_size(len);
	newinp = ft_alignment(size, input);
	if (flags->sha)
		hash = ft_initialize_buff_sha256(NULL);
	else
		hash = ft_initialize_buff_sha224(NULL);
	arr = ft_char2int_sha256(newinp, size / 4, size);
	arr = ft_write_len_sha256((len * 8), arr, ((size / 4) - 1));
	hash = ft_alg_sha256(size, arr, hash);
	if (flags->sha)
		ft_print_hash_256(hash);
	else if (flags->sha224)
		ft_print_hash_224(hash);
}

void	ft_sha512_flag(size_t len, char *input, t_flags *flags)
{
	t_ullint	size;
	t_uchar		*newinp;
	t_ullint	*res;
	t_ullint	*hash;

	size = ft_find_size_sha512(len);
	newinp = ft_alignment_sha512(size, input);
	if (flags->sha512)
		res = ft_initialize_buff_512(NULL);
	else
		res = ft_initialize_buff_384(NULL);
	hash = ft_char2int_sha512(newinp, (ssize_t)size / 8, size);
	hash = ft_write_len_sha512(len * 8, hash, (size / 8) - 1);
	hash = ft_alg_sha512(size, hash, res);
	if (flags->sha512)
		ft_print_hash_512(hash);
	else
		ft_print_hash_384(hash);
}

void	ft_find_algo(char *input, size_t len, t_flags *flags)
{
	const t_alg alg[3] = {ft_md5_flag, ft_sha256_flag, ft_sha512_flag};

	alg[flags->ind](len, input, flags);
}
