/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:41:15 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/02 12:23:40 by aryabenk         ###   ########.fr       */
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
	flags->md5 = 0;
	flags->sha = 0;
	flags->file = 0;
	flags->sha512 = 0;
	flags->sha384 = 0;
	flags->sha224 = 0;
	flags->stdin = 0;
	flags->ind = -1;
	return (flags);
}
