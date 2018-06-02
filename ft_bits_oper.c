/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_oper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:39:04 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/24 15:35:45 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_uint	ft_f(t_uint x, t_uint y, t_uint z)
{
	t_uint	res;

	res = (x & y) | ((~x) & z);
	return (res);
}

t_uint	ft_g(t_uint x, t_uint y, t_uint z)
{
	t_uint res;

	res = (x & z) | ((~z) & y);
	return (res);
}

t_uint	ft_h(t_uint x, t_uint y, t_uint z)
{
	t_uint res;

	res = x ^ y ^ z;
	return (res);
}

t_uint	ft_l(t_uint x, t_uint y, t_uint z)
{
	t_uint res;

	res = y ^ ((~z) | x);
	return (res);
}
