/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeahoare <jeahoare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 19:32:42 by jeahoare          #+#    #+#             */
/*   Updated: 2017/10/06 16:21:39 by jjuret           ###   ########.fr       */
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
