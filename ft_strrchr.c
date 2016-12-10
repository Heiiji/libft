/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:19:50 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:36:43 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cursor;
	char	*result;

	cursor = (char *)s;
	result = NULL;
	while (*cursor != '\0')
	{
		if (*cursor == (char)c)
			result = cursor;
		cursor++;
	}
	if (c == 0)
		return (cursor);
	return (result);
}
