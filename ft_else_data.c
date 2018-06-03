/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_else_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:09:38 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/03 17:41:43 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_s_flag(char *args, t_flags *flags)
{
	int		len;

	if (!flags->r && !flags->q)
	{
		if (flags->md5)
			ft_printf("MD5 ");
		else if (flags->sha)
			ft_printf("SHA256 ");
		else if (flags->sha512)
			ft_printf("SHA512 ");
		else if (flags->sha384)
			ft_printf("SHA384 ");
		else if (flags->sha224)
			ft_printf("SHA224 ");
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
	if (flags->md5)
		ft_printf("md5: ");
	else if (flags->sha)
		ft_printf("sha256: ");
	else if (flags->sha512)
		ft_printf("sha512: ");
	else if (flags->sha384)
		ft_printf("sha384: ");
	else if (flags->sha224)
		ft_printf("sha224 ");
	tmp = ft_strtrim(args);
	ft_printf("%s: ", tmp);
	ft_strdel(&tmp);
	ft_printf("No such file or directory\n");
}

void	ft_print_fd(t_flags *flags, int fd, char *args)
{
	if (!flags->r && !flags->q && fd > 0)
	{
		if (flags->md5)
			ft_printf("MD5 ");
		else if (flags->sha)
			ft_printf("SHA256 ");
		else if (flags->sha512)
			ft_printf("SHA512 ");
		else if (flags->sha384)
			ft_printf("SHA384 ");
		else if (flags->sha224)
			ft_printf("SHA224 ");
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

void	ft_else_data(int argc, char **argv, t_flags *flags)
{
	int		i;
	int		fd;

	i = 1;
	fd = 0;
	while (argv && argv[i] && i < argc)
	{
		if ((!ft_is_flag(argv[i]) || fd != 0))
			fd = ft_from_file(fd, argv[i], flags);
		else if (argv[i][0] == '-' && argv[i][1] == 's' && \
			!argv[i][2] && flags->s && argv[i + 1])
			ft_s_flag(argv[++i], flags);
		i++;
	}
}
