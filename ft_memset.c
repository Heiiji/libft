/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:09:43 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:34:16 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cursor;

	if (len == 0)
		return (b);
	cursor = (unsigned char *)b;
	while (len > 0)
	{
		*cursor = (unsigned char)c;
		if (len)
			cursor++;
		len--;
	}
	return (b);
}
