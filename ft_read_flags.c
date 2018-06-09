/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:49:55 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/04 15:14:43 by aryabenk         ###   ########.fr       */
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

void	ft_find_alg(char **argv, int i, t_flags *fla, t_algo *algo)
{
	int ind;

	ind = 0;
	while (algo && ft_strcmp(argv[i], algo->algname))
	{
		algo = algo->next;
		ind++;
	}
	if (algo && !ft_strcmp(argv[i], algo->algname))
	{
		fla->ind = ind;
		fla->alg = ft_strdup(algo->algname);
	}
}

int		ft_check_error(char **argv, int i, t_flags *fla, t_algo *algo)
{
	if (argv && argv[i] && argv[i][0])
		ft_find_alg(argv, i, fla, algo);
	else
		ft_usage(fla, argv, algo);
	if (fla->ind == -1)
		ft_unknown_algo_error(argv, fla, i, algo);
	return (1);
}

void	ft_flags_read(int argc, char **argv, t_flags *fla, t_algo *algo)
{
	int i;

	i = 0;
	i = ft_check_error(argv, i, fla, algo);
	while (i < argc && argv[i] && argv[i][0] && !fla->file)
	{
		if (argv[i][1] && argv[i][0] == '-' && argv[i][1] == 'p' && !argv[i][2])
			fla->p++;
		else if (argv[i][1] && argv[i][0] == '-' && argv[i][1] == 'q' \
			&& !argv[i][2])
			fla->q++;
		else if (argv[i][1] && argv[i][0] == '-' && argv[i][1] == 'r' \
			&& !argv[i][2])
			fla->r++;
		else if (argv[i][1] && argv[i][0] == '-' && argv[i][1] == 's' \
			&& !argv[i][2])
		{
			fla->s++;
			i++;
		}
		else
			ft_unknown_op_error(argv, fla, i, algo);
		i++;
	}
}
