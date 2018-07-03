# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    correction.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robert0 <fripponsupersonique@42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/30 18:20:35 by robert0           #+#    #+#              #
#    Updated: 2018/07/03 18:04:32 by robert0          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make -C libft/ fclean
make -C libft/
gcc -Wall -Wextra -Werror -I ./libft/includes/ -c get_next_line.c
gcc -Wall -Wextra -Werror -I ./libft/includes/ -c main.c
gcc -o test_gnl get_next_line.o main.o -L libft/ -lft