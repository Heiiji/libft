/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:50:39 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 17:19:30 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*mem;

	if (!s1 || !s2)
		return (NULL);
	if ((new = (char *)malloc(ft_strlen((char *)s1) + \
				ft_strlen((char *)s2) + 1)) == NULL)
		return (NULL);
	mem = new;
	while (*s1 != '\0')
	{
		*new = *s1;
		s1++;
		new++;
	}
	while (*s2 != '\0')
	{
		*new = *s2;
		s2++;
		new++;
	}
	*new = '\0';
	return (mem);
}
