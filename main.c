/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robert0 <fripponsupersonique@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 18:21:22 by robert0           #+#    #+#             */
/*   Updated: 2018/07/03 18:09:04 by robert0          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"get_next_line.h"
#include	"libft.h"

static void	ft_putline(char **line, const int v_read)
{
	if ((v_read != -1) && (line != NULL) && (*line != NULL))
	{
		ft_putendl(*line);
		ft_memdel((void **)(line));
	}
}

int		main(void)
{
	int		fd;
	int		fd2;
	char	*line;

	fd = open("fichier_test.txt", O_RDONLY);
	fd2 = open("fichier2_test.txt", O_RDONLY);
	if ((fd != -1) && (fd2 != -1))
	{
		ft_putline(&line, get_next_line(1, &line));
		close(fd);
	}

	return (0);
}
