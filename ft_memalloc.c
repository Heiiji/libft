/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:53:08 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:33:55 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

void	*ft_memalloc(size_t size)
{
	char	*dest;
	char	*assign;

	if ((dest = (char *)malloc(size)) != NULL)
	{
		assign = dest;
		while (size > 0)
		{
			*assign = '\0';
			assign++;
			size--;
		}
		return (dest);
	}
	else
		return (NULL);
}
