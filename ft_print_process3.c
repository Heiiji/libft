/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:20:19 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/10 13:01:09 by jjuret           ###   ########.fr       */
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

	*str += 1;
	tmp = (wchar_t *)malloc(sizeof(wchar_t) * 2);
	tmp[0] = va_arg(*ap, wint_t);
	tmp[1] = L'\0';
	ft_putwstr(tmp);
	free(tmp);
	g_worker[(int)'!'] = 1;
	return (ft_strdup("0"));
}

char			*process_percent(char **str, va_list *ap)
{
	char	*render;
	va_list *ap2;

	ap2 = ap;
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
	if (g_worker[(int)'+'] != 0 || ft_strchr(nbr, '-') != NULL)
		return (render);
	g_worker[(int)'+'] = 1;
	while (*(render + 1) == ' ')
		render++;
	return (process_pos_bis(render, nbr));
}
