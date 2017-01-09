/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:35:59 by jjuret            #+#    #+#             */
/*   Updated: 2017/01/09 16:30:46 by jjuret           ###   ########.fr       */
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
	g_worker[(int)'p'] = 1;
	if (ap)
		tmp = ft_itoa_base_ll(va_arg(*ap, long unsigned int), 16);
	else
		tmp = ft_strdup("\0");
	if (g_worker[(int)'.'] == 1)
	{
		free(tmp);
		return (ft_strdup("0x"));
	}
	result = (char *)malloc(sizeof(char) * ft_strlen(tmp) + 3);
	*result = '0';
	*(result + 1) = 'x';
	ft_strcpy(result + 2, tmp);
	*(result + ft_strlen(tmp) + 2) = '\0';
	free(tmp);
	return (result);
}

char			*process_hx(char **str, va_list *ap)
{
	char			*result;
	char			*tmp;
	unsigned int	leng;

	result = NULL;
	if (check_leng(*str) == 1)
	{
		tmp = ft_itoa_base((short)va_arg(*ap, int), 16);
		leng = 4;
	}
	else
	{
		tmp = ft_itoa_base((char)va_arg(*ap, int), 16);
		leng = 2;
	}
	if (ft_strlen(tmp) > leng)
	{
		result = (char*)malloc(sizeof(char) * leng + 1);
		result = ft_strncpy(result, tmp, leng);
		free(tmp);
		result[leng] = '\0';
	}
	else
		result = tmp;
	return (result);
}

int				miniconf()
{
	if (g_worker[(int)'.'] > 1)
		return (g_worker[(int)'.']);
	else
		return (g_worker[(int)'6'] >= 0) ? g_worker[(int)'6'] + 1 : 0;
}
