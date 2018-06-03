/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:49:55 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/03 18:42:29 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		ft_is_flag(char *param)
{
	if (param[0] == '-' && param[1] == 's' && !param[2])
		return (1);
	else if (param[0] == '-' && param[1] == 'p' && !param[2])
		return (1);
	else if (param[0] == '-' && param[1] == 'q' && !param[2])
		return (1);
	else if (param[0] == '-' && param[1] == 'r' && !param[2])
		return (1);
	else
		return (0);
}

void	ft_unknown_algo_error(char **argv, t_flags *fla, int i)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", argv[i]);
	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\nmd5\nsha256\nsha512\n");
	ft_printf("sha224\nsha384\n\n");
	ft_printf("Cipher commands:\n");
	if (fla->stdin)
		ft_del_doublestr(&argv);
	free(fla);
	exit(1);
}

void	ft_error(char **argv, t_flags *fla, int i)
{
	if (argv[i][0] == '-')
	{
		ft_printf("unknown option '%s'\noptions are\n", argv[i]);
		ft_printf("-p   echo STDIN to STDOUT");
		ft_printf("and append the checksum to STDOUT\n");
		ft_printf("-r   reverse the format of the output\n");
		ft_printf("-q   quiet mode\n");
		ft_printf("-s   print the sum of the given string\n");
		if (fla->stdin)
			ft_del_doublestr(&argv);
		free(fla);
		exit(1);
	}
	fla->file++;
}

void	ft_find_alg(char **argv, int i, t_flags *fla)
{
	if (!ft_strcmp(argv[i], "sha256") && !fla->md5 && !fla->sha512)
	{
		fla->sha++;
		fla->ind = 1;
	}
	else if (!ft_strcmp(argv[i], "sha512") && !fla->md5 && !fla->sha)
	{
		fla->sha512++;
		fla->ind = 2;
	}
	else if (!ft_strcmp(argv[i], "md5") && !fla->sha && !fla->sha512)
	{
		fla->md5++;
		fla->ind = 0;
	}
	else if (!ft_strcmp(argv[i], "sha384") && !fla->sha && !fla->sha512)
	{
		fla->sha384++;
		fla->ind = 2;
	}
	else if (!ft_strcmp(argv[i], "sha224") && !fla->sha && !fla->sha512)
	{
		fla->sha224++;
		fla->ind = 1;
	}
}

void	ft_flags_read(int argc, char **argv, t_flags *fla)
{
	int i;

	i = 0;
	ft_find_alg(argv, i, fla);
	if (fla->ind == -1)
		ft_unknown_algo_error(argv, fla, i);
	i++;
	while (i < argc && argv[i] && argv[i][0] && argv[i][1] && !fla->file)
	{
		if (argv[i][0] == '-' && argv[i][1] == 'p' && !argv[i][2])
			fla->p++;
		else if (argv[i][0] == '-' && argv[i][1] == 'q' && !argv[i][2])
			fla->q++;
		else if (argv[i][0] == '-' && argv[i][1] == 'r' && !argv[i][2])
			fla->r++;
		else if (argv[i][0] == '-' && argv[i][1] == 's' && !argv[i][2])
		{
			fla->s++;
			i++;
		}
		else
			ft_error(argv, fla, i);
		i++;
	}
}
