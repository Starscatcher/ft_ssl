/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:20:52 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/04 10:17:19 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		ft_words(char *arr, char elem)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (arr && arr[i])
	{
		if (arr[i] && arr[i] != elem)
		{
			count++;
			if (arr[i] == '\"')
			{
				i++;
				while (arr[i] != '\"')
					i++;
			}
			while (arr[i] && arr[i] != elem)
				i++;
		}
		else
			i++;
	}
	return (count);
}

int		ft_word_len(char *arr, char elem)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (arr && arr[i] && arr[i] != elem)
	{
		if (arr[i] == '\"')
		{
			i++;
			while (arr[i] && arr[i] != '\"')
			{
				i++;
				len++;
			}
			if (arr[i] && arr[i] == '\"')
				i++;
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}

char	**ft_write2arr(char *arr, int *k, int *i, char **res)
{
	int j;

	j = 0;
	while (arr[*k] && arr[*k] != ' ')
	{
		if (arr[*k] == '\"')
		{
			++*k;
			while (arr[*k] && arr[*k] != '\"')
			{
				res[*i][j++] = arr[*k];
				++*k;
			}
			if (arr[*k] && arr[*k] == '\"')
				++*k;
			while (arr[*k] && arr[*k] == '\n')
				++*k;
		}
		else
		{
			res[*i][j++] = arr[*k];
			++*k;
		}
	}
	return (res);
}

char	**ft_ssl_split(char *arr, char elem)
{
	char	**res;
	int		i;
	int		k;

	i = 0;
	k = 0;
	res = (char**)malloc(sizeof(char*) * ft_words(arr, elem) + 1);
	while (arr && arr[k])
	{
		while (arr[k] && (arr[k] == elem || arr[k] == '\n'))
			k++;
		if (arr[k])
		{
			res[i] = ft_strnew((size_t)ft_word_len(arr + k, elem));
			res = ft_write2arr(arr, &k, &i, res);
		}
		else
			res[i] = ft_strnew(0);
		i++;
	}
	res[i] = NULL;
	return (res);
}
