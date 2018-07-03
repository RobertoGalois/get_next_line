/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robert0 <fripponsupersonique@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:45:47 by robert0           #+#    #+#             */
/*   Updated: 2018/07/03 18:37:05 by robert0          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<unistd.h>
#include	"libft.h"
#include	"get_next_line.h"

static void	dllist(t_listc *listc)
{
	t_listc	*tmp_list;

	while (listc != NULL)
	{
		tmp_list = listc->next;
		free(listc);
		listc = tmp_list;
	}
}

t_listc		*crlist(void)
{
	t_listc	*listc;

	listc = (t_listc *)(malloc(sizeof (t_listc)));
	if (listc != NULL)
	{
		listc->next = NULL;
		listc->c = '\0';
	}

	return (listc);
}

static int	ft_linetolist(int const fd, t_listc *listc, int *ret)
{
	int		ret_count;
	int		malloc_err;
	char	buf[1];
	t_listc	*ptr_listc;

	ret_count = 0;
	malloc_err = 0;
	ptr_listc = listc;
	while ((malloc_err == 0) && ((*ret) = (read(fd, buf, 1)) == 1)
			&& (buf[0] != '\n'))
	{
		ret_count++;
		listc->c = buf[0];
		listc->next = crlist();
		listc = listc->next;
		if (listc == NULL)
		{
			dllist(ptr_listc);
			malloc_err = 1;
			ret_count = -1;
		}
	}

	return (ret_count);
}

static int	ft_check_params(int const fd, char **line, t_listc *listc)
{
	int		buf[1];

	if (fd == -1)
		return (0);

	if (line == NULL)
		return (0);

	if (read(fd, buf, 0) == -1)
		return (0);

	if (listc == NULL)
		return (0);

	return (1);
}

/*
** get_next_line: takes a FD and an &char*
** read range of chars until a \n OR an EOF
** save it in line, and 
** return: 1 if a line were read
**         0 if EOF is reached
**        -1 if there were an error
*/
int		get_next_line(int const fd, char **line)
{
	int		ret;
	int		nb_chars;
	char	*ptr_line;
	t_listc	*listc;
	t_listc	*ptr_listc;

	ret = -1;
	if (ft_check_params(fd, line, (listc = crlist())) == 1)
	{
		if ((nb_chars = ft_linetolist(fd, (ptr_listc = listc), &ret)) >= 0)
		{
			if ((*line = ft_strnew(nb_chars)) != NULL)
			{
				ptr_line = *line;
				while (listc != NULL)
				{
					*ptr_line = (listc->c);
					listc = listc->next;
					ptr_line++;
				}
			}

			else
				ret = -1;
		}

		dllist(ptr_listc);
	}

	return (ret);
}
