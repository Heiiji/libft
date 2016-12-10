/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:12:22 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 16:52:52 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*curseur;
	unsigned int	place;

	if (s && f)
	{
		curseur = s;
		place = 0;
		while (*curseur != '\0')
		{
			f(place, curseur);
			place++;
			curseur++;
		}
	}
}
