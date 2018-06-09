/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:07:50 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/04 12:08:13 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_print_upper(t_flags *flags)
{
	int len;
	int i;

	len = (int)ft_strlen(flags->alg);
	i = 0;
	while (i < len)
	{
		ft_printf("%c", ft_toupper(flags->alg[i]));
		i++;
	}
	ft_printf(" ");
}
