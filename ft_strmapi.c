/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:53:01 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/11 12:15:22 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	int		place;
	char	*new;
	char	*memo;

	if (!(s) && !(f))
		return (NULL);
	place = 0;
	size = ft_strlen((char *)s);
	if ((new = (char *)malloc(sizeof(char) * (size + 1))) != NULL)
	{
		memo = new;
		while (*s != '\0')
		{
			*new = f(place, *s);
			place++;
			new++;
			s++;
		}
		*new = '\0';
		return (memo);
	}
	else
		return (NULL);
}
