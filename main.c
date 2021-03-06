/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:35:39 by aryabenk          #+#    #+#             */
/*   Updated: 2018/07/16 14:05:00 by aryabenk         ###   ########.fr       */
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

void	ft_find_algo(size_t len, t_flags *flags)
{
	const t_alg alg[6] = {ft_md5_flag, ft_sha256_flag, ft_sha512_flag,
			ft_sha384_flag, ft_sha224_flag, ft_base64_flag};
	alg[flags->ind](len, flags);
}

void	ft_start(t_flags *flags)
{
	flags->input = NULL;
	if (flags->p || (!flags->s && !flags->file))
		flags->input = ft_read_input(0);
	if (flags->input)
	{
		if (flags->p)
			ft_printf("%s", flags->input);
		ft_find_algo(ft_strlen(flags->input), flags);
		ft_printf("\n");
	}
	flags->r = flags->q ? 0 : flags->r;
}

int		main(int argc, char **argv)
{
	t_flags	*flags;
	t_algo	*algo;

	algo = ft_arr_with_alg(NULL);
	flags = ft_create_flags(NULL);
	if (argc == 1)
	{
		flags->input = ft_read_input(0);
		flags->stdin++;
		argv = ft_ssl_split(flags->input, ' ');
		argc = ft_find_new_argc(argv);
		ft_strdel(&flags->input);
	}
	if ((argc > 1 && !flags->stdin) || (argc > 0 && flags->stdin))
		ft_flags_read(argc, argv + (flags->stdin ? 0 : 1), flags, algo);
	if (flags->ind != -1)
	{
		ft_start(flags);
		ft_else_data(argc, argv, flags);
	}
	else if (flags->ind == -1 && argv && argv[0])
		ft_unknown_algo_error(argv, flags, 0, algo);
	else
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	ft_del_flags(flags);
	return (1);
}
