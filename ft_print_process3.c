/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:20:19 by jjuret            #+#    #+#             */
/*   Updated: 2017/01/07 17:42:53 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

char			*process_ls(char **str, va_list *ap)
{
	wchar_t	*result;
	char	*retur;

	*str += 1;
	result = va_arg(*ap, wchar_t*);
	if (result == NULL)
		return (ft_strdup("(null)"));
	retur = (char *)malloc(sizeof(char) * ft_wstrlen(result) + 1);
	ft_putwstr(result);
	ft_memset(retur, 48, ft_wstrlen(result));
	retur[ft_wstrlen(result)] = 0;
	g_worker[(int)'!'] = 1;
	return (retur);
}

char			*process_c(char **str, va_list *ap)
{
	char	*tmp;

	*str += 1;
	g_worker[(int)'c'] = 1;
	tmp = (char *)malloc(sizeof(char) * 2);
	*tmp = va_arg(*ap, int);
	*(tmp + 1) = '\0';
	if (*tmp == '\0')
		g_worker[(int)'c'] = 2;
	return (tmp);
}

char			*process_lc(char **str, va_list *ap)
{
	wchar_t	*tmp;
	char	*render;

	*str += 1;
	render = NULL;
	tmp = (wchar_t *)malloc(sizeof(wchar_t) * 2);
	tmp[0] = va_arg(*ap, wint_t);
	tmp[1] = L'\0';
	ft_putwstr(tmp);
	if (tmp[0] <= 0x7F)
		render = ft_strdup("0");
	else if (tmp[0] <= 0x7FF)
		render = ft_strdup("00");
	else if (tmp[0] <= 0xFFFF)
		render = ft_strdup("000");
	else
		render = ft_strdup("0000");
	free(tmp);
	g_worker[(int)'!'] = 1;
	return (render);
}

char			*process_percent(char **str, va_list *ap)
{
	char	*render;

	if (ap != NULL)
		render = (char *)malloc(sizeof(char) * 2);
	else
		render = (char *)malloc(sizeof(char) * 2);
	*render = '%';
	*(render + 1) = '\0';
	*str += 1;
	return (render);
}

char			*process_pos(char **str, va_list *ap)
{
	char	*nbr;
	char	*render;

	*str += 1;
	nbr = repartiteur(str, ap);
	render = nbr;
	if (g_worker[(int)'+'] != 0 || g_worker[(int)'o'] != 0 \
	|| ft_strchr(nbr, '-') != NULL || g_worker[(int)'x'] != 0)
		return (render);
	g_worker[(int)'+'] = 1;
	while (*(render + 1) == ' ' && *(render) == ' ')
		render++;
	return (process_pos_bis(render, nbr));
}
