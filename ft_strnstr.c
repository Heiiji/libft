/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:46:16 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:36:39 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

static int	checkern(const char *main, const char *baby, int len)
{
	while (*baby == *main && *baby != '\0' && len > 0)
	{
		baby++;
		main++;
		len--;
	}
	if (*baby == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*mem;
	const char	*mem2;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		mem = big;
		mem2 = little;
		if ((*big == *little) && (checkern(big, little, len) == 1))
			return ((char *)mem);
		else
		{
			big = mem;
			little = mem2;
		}
		big++;
		len--;
	}
	return (NULL);
}
