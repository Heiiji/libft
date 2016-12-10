/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:27:17 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/11 12:10:36 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	long	size;
	char	*new;
	char	*curseur;
	char	*memo;

	if (s && f)
	{
		size = ft_strlen((char *)s);
		if ((new = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
			return (NULL);
		memo = new;
		curseur = (char *)s;
		while (*curseur != '\0')
		{
			*new = f(*curseur);
			new++;
			curseur++;
		}
		*new = '\0';
		return (memo);
	}
	return (NULL);
}
