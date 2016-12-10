/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 09:48:21 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:34:59 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putstr(char const *s)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}