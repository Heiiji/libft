/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:30:23 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:36:09 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*cur;
	const char	*cur2;
	size_t		rsize;

	cur = dst;
	cur2 = src;
	rsize = (ft_strlen((char *)src)) + ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (ft_strlen((char *)src) + size);
	while (*cur != '\0')
	{
		size--;
		cur++;
	}
	while ((*cur2 != '\0') && (size > 1))
	{
		*cur = *cur2;
		cur2++;
		cur++;
		size--;
	}
	*cur = '\0';
	return (rsize);
}
