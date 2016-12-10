/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:34:08 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 13:33:09 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_isalpha(int c)
{
	if (c >= (unsigned char)'A' && c <= (unsigned char)'Z')
		return (1);
	if (c >= (unsigned char)'a' && c <= (unsigned char)'z')
		return (1);
	return (0);
}
