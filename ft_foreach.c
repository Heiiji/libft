/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:12:37 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/03 13:39:24 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	cursor;

	cursor = 0;
	while (cursor < length)
	{
		(*f)(tab[cursor]);
		cursor++;
	}
}
