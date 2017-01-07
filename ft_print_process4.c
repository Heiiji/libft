/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:12:08 by jjuret            #+#    #+#             */
/*   Updated: 2017/01/07 17:42:27 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

char			*process_dot(char **str, va_list *ap)
{
	int		precision;
	char	*result;
	char	*cur;

	precision = 0;
	cur = NULL;
	*str += 1;
	if (**str >= '0' && **str <= '9')
		precision = ft_atoi(*str);
	g_worker[(int)'.'] = precision + 1;
	while (**str >= '0' && **str <= '9')
		*str += 1;
	result = repartiteur(str, ap);
	if (ft_strchr(result, '-'))
		precision += 1;
	return (process_dot_bis(cur, result, precision, str));
}

char			*process_l(char **str, va_list *ap)
{
	char	*matcher;

	*str += 1;
	if (g_print_tools[(int)**str] != 0)
		matcher = (char *)g_print_tools[(int)**str + 100](str, ap);
	else
		return (ft_strdup(""));
	return (matcher);
}

char			*process_space(char **str, va_list *ap)
{
	char	*nbr;
	char	*render;

	*str += 1;
	nbr = repartiteur(str, ap);
	if (*(*str - 1) == 'u' || g_worker[(int)'x'] == 1 || g_worker[(int)'o'] \
	== 1 || g_worker[(int)'c'])
		return (nbr);
	if (*nbr != '-' && *nbr != '+' && *nbr != '0' && *nbr != ' ' && \
	g_worker[(int)' '] != 1 && *nbr != '%' && ft_strlen(nbr) > 0 && *nbr > 0)
	{
		g_worker[(int)' '] = 1;
		render = (char *)malloc(sizeof(char) * ft_strlen(nbr) + 2);
		ft_strcpy(render + 1, nbr);
		*render = ' ';
		free(nbr);
	}
	else
	{
		g_worker[(int)' '] = 1;
		if (*nbr == '0')
			*nbr = ' ';
		return (nbr);
	}
	return (render);
}

char			*process_lld(char **str, va_list *ap)
{
	*str += 1;
	return (ft_itoa_base_ll(va_arg(*ap, long long int), 10));
}

char			*process_llx(char **str, va_list *ap)
{
	char *result;
	char *cur;

	if (**str == 'x')
	{
		result = ft_itoa_base_ll(va_arg(*ap, long int), 16);
		cur = result;
		while (*cur)
		{
			*cur = ft_tolower(*cur);
			cur++;
		}
		return (result);
	}
	*str += 1;
	result = ft_itoa_base_ll(va_arg(*ap, long int), 16);
	return (result);
}
