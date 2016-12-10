/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:06:10 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:34:03 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *base;
	unsigned char *target;

	base = (unsigned char *)s1;
	target = (unsigned char *)s2;
	while (n > 0)
	{
		if (*base != *target)
			return (*base - *target);
		base++;
		target++;
		n--;
	}
	return (0);
}
