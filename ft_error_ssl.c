/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_ssl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:20:58 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/04 14:56:33 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_unknown_algo_error(char **argv, t_flags *fla, int i, t_algo *algo)
{
	char	*tmp;
	t_algo	*head;

	head = algo;
	tmp = ft_strtrim(argv[i]);
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", tmp);
	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\n");
	while (algo)
	{
		ft_printf("%s\n", algo->algname);
		algo = algo->next;
	}
	ft_printf("\nCipher commands:\n");
	ft_strdel(&tmp);
	if (fla->stdin)
		ft_del_doublestr(&argv);
	ft_del_algo(head);
	ft_del_flags(fla);
	exit(1);
}

void	ft_unknown_op_error(char **argv, t_flags *fla, int i, t_algo *algo)
{
	if (argv[i][0] == '-')
	{
		ft_printf("unknown option '%s'\noptions are\n", argv[i]);
		ft_printf("-p   echo STDIN to STDOUT ");
		ft_printf("and append the checksum to STDOUT\n");
		ft_printf("-r   reverse the format of the output\n");
		ft_printf("-q   quiet mode\n");
		ft_printf("-s   print the sum of the given string\n");
		if (fla->stdin)
			ft_del_doublestr(&argv);
		ft_del_algo(algo);
		free(fla);
		exit(1);
	}
	fla->file++;
}

void	ft_usage(t_flags *fla, char **argv, t_algo *algo)
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	if (fla->stdin)
		ft_del_doublestr(&argv);
	ft_del_algo(algo);
	ft_del_flags(fla);
	exit(1);
}
