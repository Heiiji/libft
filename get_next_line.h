/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:15:12 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/10 15:13:36 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 3

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct		s_reader
{
	int				fd;
	char			*cursor;
	struct s_reader	*next;
}					t_reader;

int					get_next_line(const int fd, char **line);

#endif
