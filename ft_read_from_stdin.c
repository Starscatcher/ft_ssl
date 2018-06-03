/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_stdin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:10:55 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/03 18:43:39 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		ft_find_new_argc(char **argv)
{
	int size;

	size = 0;
	while (argv && argv[size])
		size++;
	return (size);
}

void	ft_stdin_read(char **argv, int argc, t_flags *flags, char *input)
{
	flags->stdin++;
	argv = ft_ssl_split(input, ' ');
	argc = ft_find_new_argc(argv);
	ft_strdel(&input);
	ft_flags_read(argc, argv, flags);
	if (flags->md5 || flags->sha || flags->sha512 || flags->sha384 \
		|| flags->sha224)
	{
		ft_else_data(argc, argv, flags);
		if (flags->p)
		{
			input = ft_read_input(0);
			if (input)
				ft_printf("%s", input);
			ft_find_algo(input, ft_strlen(input), flags);
			ft_printf("\n");
		}
	}
	else
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
}
