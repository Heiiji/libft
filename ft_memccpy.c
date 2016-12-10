/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:29:07 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:33:57 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, \
					size_t n)
{
	unsigned char	*cursor;
	unsigned char	*copiter;
	unsigned char	*mem;

	mem = (unsigned char *)dst;
	if (n == 0)
		return (NULL);
	cursor = (unsigned char *)dst;
	copiter = (unsigned char *)src;
	while (n > 0)
	{
		*cursor = *copiter;
		if (*copiter == (unsigned char)c)
		{
			cursor++;
			return (cursor);
		}
		copiter++;
		cursor++;
		n--;
	}
	return (NULL);
}
