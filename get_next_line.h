/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robert0 <fripponsupersonique@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 18:14:35 by robert0           #+#    #+#             */
/*   Updated: 2018/07/02 21:23:15 by robert0          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__GET_NEXT_LINE_H__
 #define	__GET_NEXT_LINE_H__

 #define	BUFF_SIZE	32

 typedef struct		s_listc
 {
	char			c;
	struct s_listc	*next;
 }					t_listc;

 int		get_next_line(int const fd, char **line);

#endif
