/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:32:31 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/11 12:37:10 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*cur1;
	unsigned char	*cur2;

	cur1 = (unsigned char *)s1;
	cur2 = (unsigned char *)s2;
	while (*cur1 != '\0' && *cur2 != '\0' && n > 0)
	{
		if (*cur1 != *cur2)
			return (*cur1 - *cur2);
		cur1++;
		cur2++;
		n--;
	}
	if (*cur1 != *cur2 && *cur1 != '\0' && *cur2 != '\0' && n > 0)
		return ((int)(*cur1 - *cur2));
	if (*cur1 != *cur2 && n > 0)
		return ((int)(*cur1 - *cur2));
	return (0);
}
