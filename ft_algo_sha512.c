/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_sha512.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:04:58 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/26 16:15:01 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_ullint	*ft_generation_words_512(t_ullint *w, t_ullint *arr)
{
	int			i;
	t_ullint	a;
	t_ullint	b;

	i = 0;
	w = (t_ullint*)malloc(sizeof(t_ullint) * 80);
	while (i < 16)
	{
		w[i] = arr[i];
		i++;
	}
	while (i < 80)
	{
		a = (f_rotr5(w[i - 15], 1) \
				^ f_rotr5(w[i - 15], 8) ^ (w[i - 15] >> 7));
		b = (f_rotr5(w[i - 2], 19) ^ f_rotr5(w[i - 2], 61) ^ (w[i - 2] >> 6));
		w[i] = w[i - 16] + a + w[i - 7] + b;
		i++;
	}
	return (w);
}

t_ullint	*ft_hash_plus_newhash_512(t_ullint *hash, t_ullint *tmp)
{
	hash[A] = hash[A] + tmp[A];
	hash[B] = hash[B] + tmp[B];
	hash[C] = hash[C] + tmp[C];
	hash[D] = hash[D] + tmp[D];
	hash[E] = hash[E] + tmp[E];
	hash[F] = hash[F] + tmp[F];
	hash[G] = hash[G] + tmp[G];
	hash[H] = hash[H] + tmp[H];
	return (hash);
}

t_ullint	*ft_formula_512(t_ullint *fo, t_ullint *tmp, int i, t_ullint *words)
{
	fo[E0] = (f_rotr5(tmp[A], 28) ^ f_rotr5(tmp[A], 34) ^ f_rotr5(tmp[A], 39));
	fo[MA] = (tmp[A] & tmp[B]) ^ (tmp[A] & tmp[C]) ^ (tmp[B] & tmp[C]);
	fo[T2] = fo[E0] + fo[MA];
	fo[E1] = (f_rotr5(tmp[E], 14) ^ f_rotr5(tmp[E], 18) ^ f_rotr5(tmp[E], 41));
	fo[CH] = (tmp[E] & tmp[F]) ^ ((~tmp[E]) & tmp[G]);
	fo[T1] = tmp[H] + fo[E1] + fo[CH] + ft_return_elem(i) + words[i];
	return (fo);
}

t_ullint	*ft_round_512(t_ullint *tmp, t_ullint *words)
{
	int			i;
	t_ullint	*fo;

	fo = (t_ullint*)malloc(sizeof(t_ullint) * 6);
	i = 0;
	while (i < 80)
	{
		fo = ft_formula_512(fo, tmp, i, words);
		tmp[H] = tmp[G];
		tmp[G] = tmp[F];
		tmp[F] = tmp[E];
		tmp[E] = tmp[D] + fo[T1];
		tmp[D] = tmp[C];
		tmp[C] = tmp[B];
		tmp[B] = tmp[A];
		tmp[A] = fo[T1] + fo[T2];
		i++;
	}
	free(fo);
	return (tmp);
}

t_ullint	*ft_alg_sha512(t_ullint s, t_ullint *a, t_ullint *hash)
{
	t_ullint	j;
	t_ullint	*tmp;
	t_ullint	*words;
	int			g;

	g = 0;
	j = 0;
	while (j < s)
	{
		words = ft_generation_words_512(NULL, a + g);
		tmp = ft_copy_hash_512(hash);
		tmp = ft_round_512(tmp, words);
		hash = ft_hash_plus_newhash_512(hash, tmp);
		g += 16;
		j += 128;
		free(tmp);
		free(words);
	}
	free(a);
	return (hash);
}
