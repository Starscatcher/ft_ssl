/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:41:15 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/04 13:22:21 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_md	*ft_create_md(t_md *lst)
{
	lst = (t_md*)malloc(sizeof(t_md));
	lst->a = 0;
	lst->aa = 0;
	lst->next = NULL;
	return (lst);
}

t_flags	*ft_create_flags(t_flags *flags)
{
	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->p = 0;
	flags->q = 0;
	flags->r = 0;
	flags->s = 0;
	flags->file = 0;
	flags->stdin = 0;
	flags->ind = -1;
	flags->alg = NULL;
	return (flags);
}

void	ft_del_flags(t_flags *flags)
{
	ft_strdel(&flags->alg);
	free(flags);
}

t_algo	*ft_arr_with_alg(t_algo *algo)
{
	t_algo *head;

	algo = (t_algo*)malloc(sizeof(t_algo));
	head = algo;
	algo->algname = ft_strdup("md5");
	algo->next = (t_algo*)malloc(sizeof(t_algo));
	algo = algo->next;
	algo->algname = ft_strdup("sha256");
	algo->next = (t_algo*)malloc(sizeof(t_algo));
	algo = algo->next;
	algo->algname = ft_strdup("sha512");
	algo->next = (t_algo*)malloc(sizeof(t_algo));
	algo = algo->next;
	algo->algname = ft_strdup("sha384");
	algo->next = (t_algo*)malloc(sizeof(t_algo));
	algo = algo->next;
	algo->algname = ft_strdup("sha224");
	algo->next = (t_algo*)malloc(sizeof(t_algo));
	algo = algo->next;
	algo->algname = ft_strdup("base64");
	algo->next = NULL;
	return (head);
}

void	ft_del_algo(t_algo *algo)
{
	t_algo *head;

	head = algo;
	while (head)
	{
		head = algo->next;
		free(algo);
		algo = head;
	}
}
