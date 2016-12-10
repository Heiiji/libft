/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:45:34 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/03 13:55:28 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	cursor;

	cursor = 0;
	if (nb < 0)
		return (0);
	while ((cursor * cursor) < nb)
		cursor++;
	if ((cursor * cursor) > nb)
		return (0);
	return (cursor);
}
