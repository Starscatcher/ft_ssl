/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_else_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:09:38 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/10 17:18:31 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_s_flag(char *args, t_flags *flags)
{
	int		len;

	if (!flags->r && !flags->q)
	{
		ft_print_upper(flags);
		ft_printf("(\"%s\") = ", args);
	}
	len = (int)ft_strlen(args);
	ft_find_algo(ft_strdup(args), len, flags);
	flags->s--;
	if (flags->r && !flags->q)
		ft_printf(" \"%s\"\n", args);
	else
		ft_printf("\n");
}

void	ft_print_notfd(t_flags *flags, char *args)
{
	char *tmp;

	ft_printf("ft_ssl: ");
	ft_printf("%s: ", flags->alg);
	tmp = ft_strtrim(args);
	ft_printf("%s: ", tmp);
	ft_strdel(&tmp);
	ft_printf("No such file or directory\n");
}

void	ft_print_fd(t_flags *flags, int fd, char *args)
{
	if (!flags->r && !flags->q && fd > 0)
	{
		ft_print_upper(flags);
		ft_printf("(%s) = ", args);
	}
	else if (fd == -1)
		ft_print_notfd(flags, args);
}

int		ft_from_file(int fd, char *input, t_flags *flags)
{
	char	*args;

	fd = open(input, O_RDONLY);
	ft_print_fd(flags, fd, input);
	if (fd > 0)
	{
		args = ft_read_input(fd);
		ft_find_algo(args, (int)ft_strlen(args), flags);
		if (flags->r && !flags->q)
			ft_printf(" %s\n", input);
		else
			ft_printf("\n");
	}
	flags->s = 0;
	return (fd);
}

void	ft_add_flags(t_flags *flags, char **argv, int i)
{
	if (argv[i][1] && argv[i][0] == '-' && argv[i][1] == 'p' && !argv[i][2])
	{
		flags->p = 1;
		ft_start(flags);
		flags->p = 0;
	}
	else if (argv[i][1] && argv[i][0] == '-' && argv[i][1] == 'q' \
 					&& !argv[i][2])
		flags->q++;
	else if (argv[i][1] && argv[i][0] == '-' && argv[i][1] == 'r' \
 					&& !argv[i][2])
		flags->r++;
}

void	ft_else_data(int argc, char **argv, t_flags *flags)
{
	int		i;
	int		fd;

	i = flags->stdin ? 1 : 2;
	fd = 0;
	flags->r = 0;
	flags->q = 0;
	while (argv && argv[i] && i < argc)
	{
		if ((!ft_is_flag(argv[i]) || fd != 0) && argv[i][0])
			fd = ft_from_file(fd, argv[i], flags);
		else if (ft_is_flag(argv[i]))
		{
			if (argv[i][0] == '-' && argv[i][1] == 's' && \
			!argv[i][2] && argv[i + 1])
				ft_s_flag(argv[++i], flags);
			else
				ft_add_flags(flags, argv, i);
		}
		i++;
	}
}
