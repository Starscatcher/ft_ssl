/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:49:55 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/02 12:50:20 by aryabenk         ###   ########.fr       */
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
	else if (param[0] == '-' && param[1] == 'c' && !param[2])
		return (1);
	else if (param[0] == '-' && param[1] == 'b' && !param[2])
		return (1);
	else if (param[0] == '-' && param[1] == 'h' && !param[2])
		return (1);
	else
		return (0);
}

void	ft_unknown_option_error(char *args, t_flags *fla)
{
	ft_printf("unknown option '%s'\noptions are\n", args);
	ft_printf("-c   to output the digest with separating colons\n");
	ft_printf("-p   echo STDIN to STDOUT");
	ft_printf("and append the checksum to STDOUT\n");
	ft_printf("-r   reverse the format of the output\n");
	ft_printf("-q   quiet mode\n");
	ft_printf("-s   print the sum of the given string\n");
	ft_printf("-b   output in binary form\n");
	ft_printf("-h   help\n");
	free(fla);
	exit(1);
}

void	ft_error(char *args, t_flags *fla, int i)
{
	if (!ft_is_flag(args))
	{
		if (i == 1)
		{
			ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", args);
			ft_printf("Standard commands:\n\n");
			ft_printf("Message Digest commands:\nmd5\nsha256\nsha512\n\n");
			ft_printf("Cipher commands:\n");
			free(fla);
			exit(1);
		}
		if (args[0] == '-')
		{
			ft_unknown_option_error(args, fla);
		}
		fla->file++;
	}
}

void	ft_find_alg(char **argv, int *i, t_flags *fla)
{
	if (!ft_strcmp(argv[*i], "sha256") && !fla->md5 && !fla->sha512)
	{
		fla->sha++;
		++*i;
	}
	else if (!ft_strcmp(argv[*i], "sha512") && !fla->md5 && !fla->sha)
	{
		fla->sha512++;
		++*i;
	}
	else if (!ft_strcmp(argv[*i], "md5") && !fla->sha && !fla->sha512)
	{
		fla->md5++;
		++*i;
	}
	else if (!ft_strcmp(argv[*i], "sha384") && !fla->sha && !fla->sha512)
	{
		fla->sha384++;
		++*i;
	}
	else if (!ft_strcmp(argv[*i], "sha224") && !fla->sha && !fla->sha512)
	{
		fla->sha224++;
		++*i;
	}
}

void	ft_flags_read(int argc, char **argv, t_flags *fla)
{
	int i;

	i = 1;
	ft_find_alg(argv, &i, fla);
	while (i < argc && argv[i][0] && argv[i][1] && !fla->file)
	{
		fla->p += argv[i][0] == '-' && argv[i][1] == 'p' && !argv[i][2] ? 1 : 0;
		fla->q += argv[i][0] == '-' && argv[i][1] == 'q' && !argv[i][2] ? 1 : 0;
		fla->r += argv[i][0] == '-' && argv[i][1] == 'r' && !argv[i][2] ? 1 : 0;
		fla->c += argv[i][0] == '-' && argv[i][1] == 'c' && !argv[i][2] ? 1 : 0;
		fla->b += argv[i][0] == '-' && argv[i][1] == 'b' && !argv[i][2] ? 1 : 0;
		fla->h += argv[i][0] == '-' && argv[i][1] == 'h' && !argv[i][2] ? 1 : 0;
		if (argv[i][0] == '-' && argv[i][1] == 's' && !argv[i][2])
		{
			fla->s++;
			i++;
		}
		else
			ft_error(argv[i], fla, i);
		i++;
	}
}
