/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:35:39 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/10 12:52:55 by aryabenk         ###   ########.fr       */
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

void	ft_find_algo(char *input, size_t len, t_flags *flags)
{
	const t_alg alg[6] = {ft_md5_flag, ft_sha256_flag, ft_sha512_flag,
			ft_sha384_flag, ft_sha224_flag, ft_base64_flag};

	alg[flags->ind](len, input);
}

void	ft_start(t_flags *flags)
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
}

int		main(int argc, char **argv)
{
	t_flags	*flags;
	char	*input;
	t_algo	*algo;

	algo = ft_arr_with_alg(NULL);
	flags = ft_create_flags(NULL);
	if (argc == 1)
	{
		input = ft_read_input(0);
		flags->stdin++;
		argv = ft_ssl_split(input, ' ');
		argc = ft_find_new_argc(argv);
		ft_strdel(&input);
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
