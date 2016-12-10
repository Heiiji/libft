/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:08:58 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:35:06 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cursor;

	cursor = (char *)s;
	while (*cursor != '\0' && *cursor != (char)c)
		cursor++;
	if (c == 0 || (char)c == *cursor)
		return (cursor);
	return (NULL);
}
