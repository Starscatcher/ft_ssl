#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 16:40:55 by aryabenk          #+#    #+#              #
#    Updated: 2018/03/13 16:40:56 by aryabenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ssl

SRC = ./ft_algo_md5.c ./ft_algo_sha256.c ./ft_algo_sha512.c ./ft_bits_oper.c \
        ./ft_create_blocks_sha256.c ./ft_create_blocks_sha512.c ./ft_del_md.c \
        ./ft_else_data.c ./ft_initialize_buff.c ./ft_lst_create.c \
        ./ft_print_hash.c ./ft_read_flags.c ./ft_read_input.c \
        ./main.c ./ft_copy_hash.c ./ft_find_algo.c ./ft_print_upper.c \
        ./ft_create_blocks_md5.c ./ft_rotr.c ./ft_return_elem.c \
        ./ft_ssl_split.c ./ft_error_ssl.c ./ft_base64.c

MLIB = make -C libftprintf

LIB = libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MLIB) clean

fclean: clean
	rm -f $(NAME)
	$(MLIB) fclean

re: fclean all
