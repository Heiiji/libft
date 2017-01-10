/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:20:19 by jjuret            #+#    #+#             */
/*   Updated: 2017/01/10 15:25:02 by jjuret           ###   ########.fr       */
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
	int		leng;

	*str += 1;
	result = va_arg(*ap, wchar_t*);
	if (result == NULL)
		return (ft_strdup("(null)"));
	if (g_worker[(int)'.'] > 0)
		leng = g_worker[(int)'.'] - 1;
	else
		leng = ft_wstrlen(result);
	retur = (char *)malloc(sizeof(char) * leng + 1);
	ft_putnwstr(result, leng);
	ft_memset(retur, 48, leng);
	retur[leng] = 0;
	g_worker[(int)'!'] = 1;
	return (retur);
}

char			*process_c(char **str, va_list *ap)
{
	char	*tmp;

	g_worker[(int)'c'] = 1;
	if (check_leng(*str) == 11 || check_leng(*str) == 12)
		return (process_lc(str, ap));
	*str += 1;
	tmp = (char *)malloc(sizeof(char) * 2);
	*tmp = (char)va_arg(*ap, int);
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
	g_worker[(int)'C'] = 1;
	tmp = (wchar_t *)malloc(sizeof(wchar_t) * 2);
	tmp[0] = va_arg(*ap, wint_t);
	if (*tmp == 0)
		g_worker[(int)'C'] = 2;
	tmp[1] = L'\0';
	ft_putwstr(tmp);
	if (tmp[0] <= 0x7F)
		render = ft_strdup("1");
	else if (tmp[0] <= 0x7FF)
		render = ft_strdup("12");
	else if (tmp[0] <= 0xFFFF)
		render = ft_strdup("123");
	else
		render = ft_strdup("1234");
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
	if (g_worker[(int)'+'] != 0 || g_worker[(int)'o'] != 0 || \
	ft_strchr(nbr, '-') != NULL || g_worker[(int)'x'] != 0 || \
	g_worker[(int)'c'] != 0 || g_worker[(int)'C'] != 0 || g_worker[(int)'p'] \
	!= 0)
		return (render);
	g_worker[(int)'+'] = 1;
	while (*(render + 1) == ' ' && *(render) == ' ')
		render++;
	return (process_pos_bis(render, nbr));
}
