/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:34:02 by aryabenk          #+#    #+#             */
/*   Updated: 2018/07/16 14:10:45 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <unistd.h>
# include <stdlib.h>
# include "./libftprintf/libft/libft.h"
# include <inttypes.h>

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;
typedef unsigned long long int	t_ullint;

# define BUFF_SIZE 1

# define A 0
# define B 1
# define C 2
# define D 3
# define E 4
# define F 5
# define G 6
# define H 7
# define E0 0
# define MA 1
# define T2 2
# define E1 3
# define CH 4
# define T1 5

typedef struct	s_md
{
	unsigned int	a;
	unsigned int	aa;
	struct s_md		*next;
}				t_md;

typedef struct	s_flags
{
	int		p;
	int		q;
	int		r;
	int		s;
  	int 	e;
  	int		d;
	int		file;
	int		stdin;
	int		ind;
	char	*alg;
  	char	*input;
}				t_flags;

typedef void	(*t_alg)(size_t, t_flags *flags);

typedef struct	s_algo
{
	char			*algname;
	struct s_algo	*next;
}				t_algo;

void			ft_start(t_flags *flags);
void			ft_base64_flag(size_t len, t_flags *flags);
void			ft_del_flags(t_flags *flags);
void			ft_md5_flag(size_t len, t_flags *flags);
void			ft_sha224_flag(size_t len, t_flags *flags);
void			ft_sha256_flag(size_t len, t_flags *flags);
void			ft_sha384_flag(size_t len, t_flags *flags);
void			ft_sha512_flag(size_t len, t_flags *flags);
void			ft_del_algo(t_algo *algo);
t_algo			*ft_arr_with_alg(t_algo *algo);
void			ft_print_upper(t_flags *flags);
void			ft_usage(t_flags *fla, char **argv, t_algo *algo);
void			ft_unknown_op_error(char **ar, t_flags *fla, int i, t_algo *al);
void			ft_unknown_algo_error(char **ar, t_flags *fl, int i, t_algo *a);
char			**ft_ssl_split(char *arr, char elem);
void			ft_find_algo(size_t  len, t_flags *flags);
t_ullint		ft_find_size_sha512(t_ullint len);
t_ullint		*ft_initialize_buff_512(t_ullint *hash);
t_uchar			*ft_alignment_sha512(t_ullint size, char *input);
t_ullint		*ft_char2int_sha512(t_uchar *b, ssize_t n, t_ullint s);
t_ullint		*ft_write_len_sha512(t_ullint len, t_ullint *data, t_ullint i);
t_ullint		*ft_copy_hash_512(t_ullint *hash);
t_ullint		*ft_alg_sha512(t_ullint s, t_ullint *a, t_ullint *hash);
void			ft_print_hash_512(t_ullint *hash);
ssize_t			ft_find_size(ssize_t len);
t_uint			*ft_initialize_buff_sha256(t_uint *arr);
t_uchar			*ft_alignment(ssize_t size, char *input);
t_uint			*ft_write_len_sha256(ssize_t len, t_uint *data, ssize_t i);
t_uint			*ft_char2int_sha256(t_uchar *bef, ssize_t news, ssize_t size);
t_uint			*ft_alg_sha256(ssize_t size, t_uint *arr, t_uint *hash);
void			ft_print_hash_256(t_uint *res);
t_uint			*ft_write_len_md5(ssize_t len, t_uint *data, ssize_t i);
void			ft_initialize_buff_md5(t_md *lst);
t_uint			*ft_char2int_md5(t_uchar *bef, ssize_t newsize, ssize_t size);
void			ft_alg_md5(t_md *hash, ssize_t size, t_uint *arr);
void			ft_print_hash_md5(t_md *hash);
t_uint			*ft_initialize_buff_sha224(t_uint *hash);
void			ft_print_hash_224(t_uint *hash);
t_ullint		*ft_initialize_buff_384(t_ullint *hash);
void			ft_print_hash_384(t_ullint *hash);
void			ft_else_data(int ar, char **a, t_flags *fl);
t_uint			*ft_copy_hash(t_uint *hash);
void			ft_del_md(t_md *md);
t_ullint		ft_return_elem(int i);
int				ft_is_flag(char *param);
char			*ft_read_input(int fd);
void			ft_flags_read(int argc, char **argv, t_flags *fla, t_algo *alg);
t_flags			*ft_create_flags(t_flags *flags);
t_md			*ft_create_md(t_md *lst);
t_uint			f_rotr(t_uint a, int s);
t_ullint		f_rotr5(t_ullint a, int s);
t_uint			ft_f(t_uint x, t_uint y, t_uint z);
t_uint			ft_g(t_uint x, t_uint y, t_uint z);
t_uint			ft_h(t_uint x, t_uint y, t_uint z);
t_uint			ft_l(t_uint x, t_uint y, t_uint z);

#endif
