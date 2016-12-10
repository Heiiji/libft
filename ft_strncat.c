/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:21:57 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:36:24 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*cur;
	char	*cur2;

	cur = (char *)s1;
	cur2 = (char *)s2;
	while (*cur != '\0')
		cur++;
	while (*cur2 != '\0' && n > 0)
	{
		*cur = *cur2;
		cur2++;
		cur++;
		n--;
	}
	*cur = '\0';
	return (s1);
}
