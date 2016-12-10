/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:22:59 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/12 12:09:51 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "./libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptdst;
	char	*ptsrc;

	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		ptdst = (char *)dst;
		ptsrc = (char *)src;
		while (len > 0)
		{
			len--;
			ptdst[len] = ptsrc[len];
		}
	}
	return (dst);
}
