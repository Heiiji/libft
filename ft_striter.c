/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:56:10 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 16:51:55 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	char *curseur;

	if (s && f)
	{
		curseur = s;
		while (*curseur != '\0')
		{
			f(curseur);
			curseur++;
		}
	}
}
