/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:38:07 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/22 16:38:08 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*ft_read_input(int fd)
{
	char		*res;
	ssize_t		ret;
	char		buf[BUFF_SIZE + 1];

	res = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		res = ft_reallcat(res, buf);
	}
	return (res);
}
