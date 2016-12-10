/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:15:35 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:33:07 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_isalnum(int c)
{
	if (c >= (unsigned char)'A' && c <= (unsigned char)'Z')
		return (1);
	if (c >= (unsigned char)'a' && c <= (unsigned char)'z')
		return (1);
	if (c >= (unsigned char)'0' && c <= (unsigned char)'9')
		return (1);
	return (0);
}
