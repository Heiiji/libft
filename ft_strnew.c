/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:00:23 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:36:36 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*dest;
	char	*init;

	if ((dest = (char *)malloc(size + 1)))
	{
		init = dest;
		while (size > 0)
		{
			*init = '\0';
			init++;
			size--;
		}
		*init = '\0';
		return (dest);
	}
	else
		return (NULL);
}
