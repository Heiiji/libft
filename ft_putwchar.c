/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:25:11 by jjuret            #+#    #+#             */
/*   Updated: 2016/11/30 16:22:51 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <unistd.h>
#include <wchar.h>

void	ft_putwchar(wchar_t c)
{
	ft_putwchar_fd(c, STDOUT_FILENO);
}
