/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:16:18 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:35:02 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*cur;
	char	*cur2;

	cur = (char *)s1;
	cur2 = (char *)s2;
	while (*cur != '\0')
		cur++;
	while (*cur2 != '\0')
	{
		*cur = *cur2;
		cur2++;
		cur++;
	}
	*cur = '\0';
	return (s1);
}
