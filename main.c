/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:35:39 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/02 12:49:17 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_start(t_flags *flags, int argc, char **argv)
{
	char	*input;

	input = NULL;
	if (flags->p || (!flags->s && !flags->file))
		input = ft_read_input(0);
	if (input)
	{
		if (flags->p)
			ft_printf("%s", input);
		ft_find_algo(input, ft_strlen(input), NULL, flags);
		ft_printf("\n");
	}
	flags->r = flags->q ? 0 : flags->r;
	ft_else_data(argc, argv, flags, NULL);
}

int		main(int argc, char **argv)
{
	t_flags	*flags;

	flags = ft_create_flags(NULL);
	ft_flags_read(argc, argv, flags);
	if (flags->h)
		ft_h_flag(flags);
	if (flags->md5 || flags->sha || flags->sha512 || flags->sha384 \
		|| flags->sha224)
		ft_start(flags, argc, argv);
	else
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	free(flags);
	system("leaks ft_ssl");
	return (1);
}
