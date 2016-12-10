/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:31:43 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:36:49 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

static int	checker(const char *main, const char *baby)
{
	while (*baby == *main && *baby != '\0')
	{
		baby++;
		main++;
	}
	if (*baby == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strstr(const char *big, const char *little)
{
	const char	*mem;
	const char	*mem2;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0')
	{
		mem = big;
		mem2 = little;
		if ((*big == *little) && (checker(big, little) == 1))
			return ((char *)mem);
		else
		{
			big = mem;
			little = mem2;
		}
		big++;
	}
	return (NULL);
}
