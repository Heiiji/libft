/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:35:59 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/15 15:44:38 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

char			*process_p(char **str, va_list *ap)
{
	char	*result;
	char	*tmp;

	*str += 1;
	if (ap)
		tmp = ft_itoa_base_ll(va_arg(*ap, long unsigned int), 16);
	else
		tmp = ft_strdup("\0");
	result = (char *)malloc(sizeof(char) * ft_strlen(tmp) + 3);
	*result = '0';
	*(result + 1) = 'x';
	ft_strcpy(result + 2, tmp);
	*(result + ft_strlen(tmp) + 2) = '\0';
	free(tmp);
	return (result);
}
