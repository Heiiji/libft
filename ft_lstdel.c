/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:54:58 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/09 19:26:31 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	if (alst && *alst)
	{
		next = (*alst)->next;
		if (next != NULL)
		{
			ft_lstdel(&next, del);
			(*alst)->next = NULL;
		}
		ft_lstdelone(alst, del);
	}
}
