/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 19:32:42 by jjuret            #+#    #+#             */
/*   Updated: 2017/10/09 11:01:43 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFF_SIZE 32

int	get_next_line(int const fd, char **line);

#endif
