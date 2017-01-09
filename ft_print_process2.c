/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:52:59 by jjuret            #+#    #+#             */
/*   Updated: 2017/01/09 15:09:28 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

char			*process_x(char **str, va_list *ap)
{
	char	*result;
	int		tmp;

	*str += 1;
	result = NULL;
	g_worker[(int)'x'] = 1;
	if (check_leng(*str) == 12 || check_leng(*str) == 31)
		result = ft_itoa_base_ll(va_arg(*ap, long long int), 16);
	if (check_leng(*str) == 11)
		result = ft_itoa_base_l(va_arg(*ap, long int), 16);
	if (check_leng(*str) == 21)
		result = ft_itoa_base_ll(va_arg(*ap, uintmax_t), 16);
	if (result == NULL)
	{
		if (check_leng(*str) == 1 || check_leng(*str) == 2)
			return (process_hx(str, ap));
		tmp = va_arg(*ap, int);
		result = ft_itoa_base(tmp, 16);
		if (ft_strlen(result) > 8 || tmp == 0)
		{
			free(result);
			return (ft_strdup("0"));
		}
	}
	return (result);
}

char			*process_lx(char **str, va_list *ap)
{
	char *result;
	char *cur;

	result = process_x(str, ap);
	cur = result;
	while (*cur)
	{
		*cur = ft_toupper(*cur);
		cur++;
	}
	return (result);
}

char			*process_0(char **str, va_list *ap)
{
	char	*tmp;
	char	*work;

	*str += 1;
	g_worker[(int)'0'] = 1;
	work = repartiteur(str, ap);
	if (g_worker[(int)'-'] > 0)
		return (work);
	tmp = work;
	if ((*tmp == '+' || *tmp == '-') && *(tmp + 1) == ' ')
		tmp++;
	while (*tmp == ' ')
	{
		*tmp = '0';
		tmp++;
	}
	if (g_worker[(int)' '] == 1 && tmp != work)
		*(tmp - 1) = ' ';
	return (process_0_bis(tmp, work));
}

char			*process_nbr(char **str, va_list *ap)
{
	char	*tmp;
	char	*work;
	char	*result;
	int		len;

	tmp = *str;
	while ((**str >= '0') && (**str <= '9'))
		*str += 1;
	len = ft_atoi(tmp);
	g_worker[(int)'6'] = len;
	work = repartiteur(str, ap);
	if (g_worker[(int)'c'] == 2)
		len -= 1;
	tmp = (char*)malloc(sizeof(char) * (len + ft_strlen(work) + 1));
	result = tmp;
	if (*work != '\0')
		len -= ft_strlen(work);
	while (len-- > 0)
	{
		*tmp = ' ';
		tmp++;
	}
	ft_strcpy(tmp, work);
	free(work);
	return (result);
}

char			*process_s(char **str, va_list *ap)
{
	char	*result;

	g_worker[(int)'+'] = -1;
	if (check_leng(*str) == 11 || check_leng(*str) == 12)
		return (process_ls(str, ap));
	*str += 1;
	if ((result = va_arg(*ap, char*)))
	{
		if (*result != '\0')
			return (ft_strdup(result));
		else
			return (ft_strdup("\0"));
	}
	else
		return (ft_strdup("(null)"));
}
