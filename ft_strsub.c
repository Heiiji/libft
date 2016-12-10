/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:08:18 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 17:52:05 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*curseur;
	char	*result;
	char	*memo;

	if (!s)
		return (NULL);
	curseur = (char *)s;
	curseur += start;
	if ((result = (char *)malloc(len + 1)))
	{
		memo = result;
		while (len > 0)
		{
			*result = *curseur;
			curseur++;
			result++;
			len--;
		}
		*result = '\0';
		return (memo);
	}
	else
		return (NULL);
}
