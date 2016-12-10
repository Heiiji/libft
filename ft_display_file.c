/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:07:24 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/11 14:32:27 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void		ft_putstr(char *tab)
{
	int		i;

	i = 0;
	while (tab[i])
		write(1, &tab[i++], 1);
}

int				ft_display_file(int argc, char **argv)
{
	int		fd;
	char	buffer[314159];
	int		nb_read;

	fd = 0;
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (1);
	else
	{
		while ((nb_read = read(fd, buffer, 314158)))
		{
			buffer[nb_read] = '\0';
			ft_putstr(buffer);
		}
	}
	if (close(fd) != 0)
		return (1);
	return (0);
}
