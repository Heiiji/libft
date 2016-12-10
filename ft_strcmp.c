/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:06:14 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:35:12 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*cur1;
	unsigned char	*cur2;

	cur1 = (unsigned char *)s1;
	cur2 = (unsigned char *)s2;
	while (*cur1 != '\0' && *cur2 != '\0')
	{
		if (*cur1 != *cur2)
			return (*cur1 - *cur2);
		cur1++;
		cur2++;
	}
	if (*cur1 != *cur2)
		return (*cur1 - *cur2);
	return (0);
}
