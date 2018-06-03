/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:35:39 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/03 17:41:43 by aryabenk         ###   ########.fr       */
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
		ft_find_algo(input, ft_strlen(input), flags);
		ft_printf("\n");
	}
	flags->r = flags->q ? 0 : flags->r;
	ft_else_data(argc, argv + 1, flags);
}

int		main(int argc, char **argv)
{
	t_flags	*flags;
	char	*input;

	flags = ft_create_flags(NULL);
	if (argc > 1)
		ft_flags_read(argc, argv + 1, flags);
	if (flags->md5 || flags->sha || flags->sha512 || flags->sha384 \
		|| flags->sha224)
		ft_start(flags, argc, argv);
	else if ((input = ft_read_input(0)))
		ft_stdin_read(argv, argc, flags, input);
	else
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	free(flags);
	//system("leaks ft_ssl");
	return (1);
}
