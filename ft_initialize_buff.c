/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_buff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:40:35 by aryabenk          #+#    #+#             */
/*   Updated: 2018/06/02 12:31:57 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_initialize_buff_md5(t_md *lst)
{
	t_md	*hash;
	t_md	*head;

	head = lst;
	lst->a = 0x67452301;
	hash = ft_create_md(NULL);
	lst->next = hash;
	lst = lst->next;
	lst->a = 0xEFCDAB89;
	hash = ft_create_md(NULL);
	lst->next = hash;
	lst = lst->next;
	lst->a = 0x98BADCFE;
	hash = ft_create_md(NULL);
	lst->next = hash;
	lst = lst->next;
	lst->a = 0x10325476;
	lst->next = head;
}

t_uint		*ft_initialize_buff_sha256(t_uint *hash)
{
	hash = (t_uint*)malloc(sizeof(t_uint) * 8);
	hash[0] = 0x6A09E667;
	hash[1] = 0xBB67AE85;
	hash[2] = 0x3C6EF372;
	hash[3] = 0xA54FF53A;
	hash[4] = 0x510E527F;
	hash[5] = 0x9B05688C;
	hash[6] = 0x1F83D9AB;
	hash[7] = 0x5BE0CD19;
	return (hash);
}

t_ullint	*ft_initialize_buff_512(t_ullint *hash)
{
	hash = (t_ullint*)malloc(sizeof(t_ullint) * 8);
	hash[0] = 0x6a09e667f3bcc908;
	hash[1] = 0xbb67ae8584caa73b;
	hash[2] = 0x3c6ef372fe94f82b;
	hash[3] = 0xa54ff53a5f1d36f1;
	hash[4] = 0x510e527fade682d1;
	hash[5] = 0x9b05688c2b3e6c1f;
	hash[6] = 0x1f83d9abfb41bd6b;
	hash[7] = 0x5be0cd19137e2179;
	return (hash);
}

t_ullint	*ft_initialize_buff_384(t_ullint *hash)
{
	hash = (t_ullint*)malloc(sizeof(t_ullint) * 8);
	hash[0] = 0xcbbb9d5dc1059ed8;
	hash[1] = 0x629a292a367cd507;
	hash[2] = 0x9159015a3070dd17;
	hash[3] = 0x152fecd8f70e5939;
	hash[4] = 0x67332667ffc00b31;
	hash[5] = 0x8eb44a8768581511;
	hash[6] = 0xdb0c2e0d64f98fa7;
	hash[7] = 0x47b5481dbefa4fa4;
	return (hash);
}

t_uint		*ft_initialize_buff_sha224(t_uint *hash)
{
	hash = (t_uint*)malloc(sizeof(t_uint) * 8);
	hash[0] = 0xc1059ed8;
	hash[1] = 0x367cd507;
	hash[2] = 0x3070dd17;
	hash[3] = 0xf70e5939;
	hash[4] = 0xffc00b31;
	hash[5] = 0x68581511;
	hash[6] = 0x64f98fa7;
	hash[7] = 0xbefa4fa4;
	return (hash);
}
