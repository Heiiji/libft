/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:22:24 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:33:03 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	char	*cursor;

	cursor = (char *)s;
	while (n--)
	{
		*cursor = '\0';
		cursor++;
	}
}
