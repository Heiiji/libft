/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:36:28 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 18:06:15 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

static int	countspace(char *str)
{
	int		size;

	size = 0;
	while ((*str == ' ') || (*str == '\n') || (*str == '\t'))
	{
		str++;
		size++;
	}
	if (*str == '\0')
		return (size);
	while (*str != '\0')
		str++;
	str--;
	while ((*str == ' ') || (*str == '\n') || (*str == '\t'))
	{
		str--;
		size++;
	}
	return (size);
}

char		*ft_strtrim(char const *s)
{
	int			size;
	char		*new;
	char		*memo;

	if (!s)
		return (NULL);
	size = ft_strlen((char*)s) - countspace((char*)s);
	if ((new = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
		s++;
	memo = new;
	while (size > 0)
	{
		*new = *s;
		s++;
		new++;
		size--;
	}
	*new = '\0';
	return (memo);
}
