/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heiji <heiji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:41:14 by heiji             #+#    #+#             */
/*   Updated: 2016/12/15 14:12:01 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <wchar.h>
#include "./libft.h"

size_t	ft_wstrlen(wchar_t *str)
{
	unsigned int	cursor;
	unsigned int	size;

	cursor = 0;
	size = 0;
	while (str[cursor] != L'\0')
	{
		if (str[cursor] <= 0x7F)
			size += 1;
		else if (str[cursor] <= 0x7FF)
			size += 2;
		else if (str[cursor] <= 0xFFFF)
			size += 3;
		else if (str[cursor] <= 0x10FFFF)
			size += 4;
		cursor++;
	}
	return (size);
}
