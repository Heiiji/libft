/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:52:59 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/09 15:12:02 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

char			*process_x(char **str, va_list *ap)
{
	char *result;

	*str += 1;
	if (*(*str - 2) == 'l')
	{
		if (*(*str - 3) == 'l')
			result = ft_itoa_base_ll(va_arg(*ap, long long int), 16);
		else
			result = ft_itoa_base_l(va_arg(*ap, long int), 16);
	}
	else
	{
		if (*(*str - 2) == 'j')
			result = ft_itoa_base_ll(va_arg(*ap, uintmax_t), 16);
		else
		{
			result = ft_itoa_base(va_arg(*ap, int), 16);
			if (ft_strlen(result) > 8)
			{
				free(result);
				return (ft_strdup("0"));
			}
		}
	}
	return (result);
}

char			*process_lx(char **str, va_list *ap)
{
	char *result;
	char *cur;

	if (*(*str - 1) != 'l')
	{
		result = process_x(str, ap);
		cur = result;
		while (*cur)
		{
			*cur = ft_toupper(*cur);
			cur++;
		}
		return (result);
	}
	*str += 1;
	result = ft_itoa_base_l(va_arg(*ap, long int), 16);
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
	while (*tmp == ' ' && *(tmp + 1) == ' ')
	{
		*tmp = '0';
		tmp++;
	}
	if (*tmp == ' ' && g_worker[(int)' '] != 1)
		*tmp = '0';
	tmp++;
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
	work = repartiteur(str, ap);
	len = ft_atoi(tmp);
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

	*str += 1;
	g_worker[(int)'+'] = -1;
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
