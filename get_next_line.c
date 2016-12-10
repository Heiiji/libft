/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:14:08 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/10 15:13:01 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

t_reader	*checker(int fd)
{
	static t_reader	*board = NULL;
	t_reader		*cursor;

	cursor = board;
	while (cursor)
	{
		if (fd == cursor->fd)
			return (cursor);
		cursor = cursor->next;
	}
	cursor = (t_reader*)malloc(sizeof(t_reader));
	cursor->fd = fd;
	if (board != NULL)
		cursor->next = board;
	else
		cursor->next = NULL;
	cursor->cursor = NULL;
	board = cursor;
	return (cursor);
}

int			extra(char **line, t_reader *worker, char *tmp, int len)
{
	*line = ft_strdup(tmp);
	free(tmp);
	free(worker->cursor);
	worker->cursor = NULL;
	return ((len) > 0 ? 1 : 0);
}

int			first_malloc(t_reader **worker, int fd)
{
	int nb_read;

	if (fd < 0)
		return (-1);
	*worker = checker(fd);
	if ((*worker)->cursor == NULL)
	{
		(*worker)->cursor = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
		if ((nb_read = read(fd, (*worker)->cursor, BUFF_SIZE)) < 1)
			return (nb_read);
		(*worker)->cursor[nb_read] = '\0';
	}
	return (1000);
}

int			extention(const int fd, char **line, t_reader *worker)
{
	int			nb_read;
	int			len;
	char		*tmp;
	char		*cur;
	char		*cur2;

	tmp = ft_strdup(worker->cursor);
	len = ft_strlen(worker->cursor);
	cur = tmp;
	free(worker->cursor);
	worker->cursor = (char *)malloc(sizeof(char) * BUFF_SIZE + len);
	cur2 = worker->cursor;
	while (*cur != '\0')
	{
		*cur2 = *cur;
		cur++;
		cur2++;
	}
	nb_read = read(fd, cur2, BUFF_SIZE);
	worker->cursor[len + nb_read] = '\0';
	if (nb_read <= 0)
		return (extra(line, worker, tmp, len));
	free(tmp);
	return (get_next_line(fd, line));
}

int			get_next_line(const int fd, char **line)
{
	t_reader	*worker;
	char		*target;
	int			nb_read;
	size_t		len;

	worker = NULL;
	if ((nb_read = first_malloc(&worker, fd)) < 1)
		return (nb_read);
	if ((target = ft_strchr(worker->cursor, '\n')))
	{
		len = target - worker->cursor;
		*line = (char *)malloc(sizeof(char) * len + 1);
		*line = ft_strncpy(*line, worker->cursor, len);
		*(*line + len) = '\0';
		target = ft_strdup(&(worker->cursor[len + 1]));
		if (*target == '\0')
		{
			free(target);
			target = NULL;
		}
		free(worker->cursor);
		worker->cursor = target;
		return (1);
	}
	return (extention(fd, line, worker));
}
