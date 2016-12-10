/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:03:35 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 15:57:44 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

size_t	ft_strlen(char *str)
{
	unsigned int	cursor;

	cursor = 0;
	while (str[cursor] != '\0')
	{
		cursor++;
	}
	return (cursor);
}
