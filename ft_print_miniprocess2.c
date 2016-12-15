/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_miniprocess2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:40:01 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/14 13:37:12 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

char			*process_0_bis(char *tmp, char *work)
{
	int	len;

	len = g_worker[(int)'.'];
	if ((*tmp == '-' || *tmp == '+') && work != tmp)
	{
		*work = *tmp;
		*tmp = '0';
	}
	tmp = work;
	if ((int)ft_strlen(work) > len - 1 && \
	len >= 0)
	{
		len -= 1;
		if (g_worker[(int)'6'] != 0)
			len -= g_worker[(int)'6'] - g_worker[(int)'.'];
		while (len < (int)ft_strlen(work))
		{
			len += 1;
			if (*tmp == '0' && *tmp != '-' && *tmp != '+')
				*tmp = ' ';
			tmp += 1;
		}
	}
	return (work);
}

char			*process_pos_bis(char *render, char *nbr)
{
	if (*render != ' ')
	{
		if (how_free_rev(nbr) < 1)
			render = (char *)malloc(sizeof(char) * ft_strlen(nbr) + 2);
		else
			render = (char *)malloc(sizeof(char) * ft_strlen(nbr) + 1);
		*render = '+';
		ft_strcpy(render + 1, nbr);
		if (how_free_rev(nbr) >= 1)
			render[ft_strlen(nbr)] = '\0';
		free(nbr);
		nbr = render;
	}
	if (*render == ' ' && ft_strchr(nbr, '+') == NULL)
		*render = '+';
	return (nbr);
}

static char		*process_dot_bis2(char *cur, char *result, int precision,\
				char **str)
{
	if (ft_strlen(result) > (size_t)precision && (*(*str - 1) == 's' || \
	*(*str - 1) == 'S'))
	{
		cur = malloc(precision + 1);
		ft_strncpy(cur, result, precision);
		cur[precision] = '\0';
		free(result);
		result = cur;
	}
	if (precision == 0 && ft_atoi(result) == 0 && *result >= '0' &&\
	*result <= '9')
	{
		free(result);
		return (ft_strdup("\0"));
	}
	return (result);
}

char			*process_dot_bis(char *cur, char *result, int precision,\
				char **str)
{
	if (ft_strlen(result) < (size_t)precision && (*(*str - 1) == 'd' || \
	*(*str - 1) == 'D' || *(*str - 1) == 'O' || *(*str - 1) == 'o' || \
	*(*str - 1) == 'U' || *(*str - 1) == 'u'))
	{
		cur = malloc(precision + 1);
		ft_memset(cur, 48, precision);
		cur[precision] = '\0';
		ft_strcpy(&cur[precision - ft_strlen(result)], result);
		if (cur[precision - ft_strlen(result)] == '-')
		{
			cur[precision - ft_strlen(result)] = '0';
			*cur = '-';
		}
		free(result);
		result = cur;
	}
	return (process_dot_bis2(cur, result, precision, str));
}

char			*put0(char *base)
{
	char	*result;

	if (*base == '0')
		return (base);
	result = (char *)malloc(sizeof(char) * ft_strlen(base) + 2);
	ft_strcpy(result + 1, base);
	result[ft_strlen(base) + 1] = '\0';
	*result = '0';
	return (result);
}
