/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:10:59 by aryabenk          #+#    #+#             */
/*   Updated: 2018/07/16 17:00:23 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_base64_print(ssize_t newlen, char *base64, int equ)
{
	int 	i;
	t_uchar	alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	i = 0;
	while (i < newlen)
	{
		ft_printf("%c",alph[(int)(base64[i])]);
		i++;
	}
	while (equ)
	{
		ft_printf("=");
		equ--;
	}
}

char	*ft_algo_base64(char *base64, ssize_t newlen, char *input)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < newlen)
	{
		base64[i++] = (t_uchar)input[j] >> 2;
		input[j] = (t_uchar)input[j] << 6;
		i < newlen ? base64[i++] = (t_uchar)input[j] >> 2 | (t_uchar)input[j + 1] >> 4 : 0;
		j++;
		input[j] = (t_uchar)input[j] << 4;
		i < newlen ? base64[i++] = (t_uchar)input[j] >> 2 | input[j + 1] >> 6 : 0;
		j++;
		input[j] = (t_uchar)input[j] << 2;
		i < newlen ? base64[i++] = (t_uchar)input[j] >> 2 : 0;
		j++;
	}
	return (base64);
}

void	ft_base64_dec_print(char *res, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("%c", res[i]);
		i++;
	}
}

char	*ft_base64_dec(int len, t_uchar *input, char *res)
{
	int		i;
	int 	j;
	char	*alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	i = 0;
	j = 0;
	while (i < len)
	{
		res[i] = (t_uchar)(ft_strchr(alph, input[j]) - alph) << 2;
		res[i++] |= (t_uchar)(ft_strchr(alph, input[++j]) - alph) >> 4;
		if (i < len)
		{
			res[i] = (t_uchar)(ft_strchr(alph, input[j]) - alph) << 4;
			res[i++] |= (t_uchar)(ft_strchr(alph, input[++j]) - alph) >> 2;
		}
		if (i < len)
		{
			res[i] = (t_uchar)(ft_strchr(alph, input[j++]) - alph) << 6;
			res[i++] |= (t_uchar)(ft_strchr(alph, input[j++]) - alph);
		}
	}
	return (res);
}

void	ft_base64_flag(size_t len, t_flags *flags)
{
	char 	*res;
	ssize_t	newlen;
	int		equ;

	if (flags->d)
	{
		len -= flags->input[len - 1] == '=' ? 1 : 0;
		len -= flags->input[len - 1] == '=' ? 1 : 0;
		len = len - len / 3;
		res = ft_strnew(len);
		res = ft_base64_dec((int)len, (t_uchar *)flags->input, res);
		ft_base64_dec_print(res, len);
	}
	else
	{
		equ = 0;
		newlen = len + len / 3;
		newlen += len % 3 > 0 ? 1 : 0;
		equ += (len + 1) % 3 == 0 ? 1 : 0;
		equ += (len + 2) % 3 == 0 ? 2 : 0;
		res = ft_strnew(newlen);
		res = ft_algo_base64(res, newlen, flags->input);
		ft_base64_print(newlen, res, equ);
	}
}
