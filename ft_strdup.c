/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:40:32 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/24 16:22:50 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

char	*ft_strdup(char *src)
{
	int		nb_char;
	int		i;
	char	*newstr;

	nb_char = 0;
	while (src[nb_char] != '\0')
		nb_char++;
	if ((newstr = malloc(sizeof(char) * (nb_char + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i <= nb_char)
	{
		newstr[i] = src[i];
		i++;
	}
	return (newstr);
}
