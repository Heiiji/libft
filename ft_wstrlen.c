/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heiji <heiji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:41:14 by heiji             #+#    #+#             */
/*   Updated: 2016/11/29 15:43:22 by heiji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <wchar.h>
#include "./libft.h"

size_t	ft_wstrlen(wchar_t *str)
{
	unsigned int	cursor;

	cursor = 0;
	while (str[cursor] != '\0')
	{
		cursor++;
	}
	return (cursor);
}
