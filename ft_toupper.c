/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:29:26 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/01 16:04:38 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_toupper(int c)
{
	if (c >= (unsigned char)'a' && c <= (unsigned char)'z')
		c -= 32;
	return (c);
}
