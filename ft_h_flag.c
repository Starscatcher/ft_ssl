/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:13:39 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/26 15:05:10 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_h_flag(t_flags *flags)
{
	free(flags);
	ft_printf(" _______________________________{sea wave}<HELP>{eoc}");
	ft_printf("_______________________________\n");
	ft_printf("|%68s|\n", "");
	ft_printf("|%20s ./ft_ssl [algorithm] [KEYS]%20s|\n", "", "");
	ft_printf("|%68s|\n", "");
	ft_printf("|%28s {sea wave}---KEYS---{eoc}%29s|\n", "", "");
	ft_printf("|%68s|\n", "");
	ft_printf("|  {sea wave}[ -h ]{eoc}           help%45s|\n", "");
	ft_printf("|  {sea wave}[ -p ]{eoc}           ");
	ft_printf("echo STDIN to STDOUT and add the hash to STDOUT  |\n");
	ft_printf("|  {sea wave}[ -c ]{eoc}           ");
	ft_printf("output with separating colons                    |\n");
	ft_printf("|  {sea wave}[ -r ]{eoc}           ");
	ft_printf("reverse output                                   |\n");
	ft_printf("|  {sea wave}[ -s ] \"string\"{eoc}  ");
	ft_printf("print the hash of the given string               |\n");
	ft_printf("|  {sea wave}[ -q ]{eoc}           ");
	ft_printf("quiet mode                                       |\n");
	ft_printf("|  {sea wave}[ -b ]{eoc}           ");
	ft_printf("binary output                                    |\n");
	ft_printf("|%68s|\n", "");
	ft_printf("|_________________________________________________________");
	ft_printf("___________|\n\n");
	exit(0);
}
