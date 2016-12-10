/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:03:46 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 16:49:04 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*memo;

	memo = dst;
	while (len > 0)
	{
		if (*src != '\0')
		{
			*dst = *src;
			src++;
		}
		else
			*dst = '\0';
		dst++;
		len--;
	}
	return (memo);
}
