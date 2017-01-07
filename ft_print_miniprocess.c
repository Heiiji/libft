/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_miniprocess.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:38:20 by jjuret            #+#    #+#             */
/*   Updated: 2017/01/07 17:45:06 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

char	*dx_extend_0(char *str, char ix)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * ft_strlen(str) + 3);
	result[0] = '0';
	result[1] = ix;
	ft_strcpy(&result[2], str);
	free(str);
	return (result);
}

char	*dx_extend_1(char *str, char ix)
{
	char	*result;

	if (how_free(str) <= 2)
		result = (char *)malloc(ft_strlen(str) + (3 - how_free(str)));
	else
		result = (char *)malloc(ft_strlen(str) + (3 - how_free_rev(str)));
	result[0] = '0';
	result[1] = ix;
	ft_strcpy(&result[2], &str[how_free(str) - 1]);
	free(str);
	return (result);
}

char	*dx_extend_2(char *str, char ix)
{
	char	*result;

	result = (char *)malloc(ft_strlen(str) + 1);
	result[ft_strlen(str)] = '\0';
	result[0] = '0';
	result[1] = ix;
	ft_strncpy(&result[2], &str[how_free(str)], ft_strlen(str) - 2);
	free(str);
	return (result);
}

void	print_action(char **format, va_list *ap, int *compteur)
{
	char	*tool;

	ft_memset(g_worker, 0, 255);
	g_worker[(int)'.'] = -5;
	g_worker[(int)'o'] = 0;
	g_worker[(int)'x'] = 0;
	g_worker[(int)'c'] = 0;
	*format += 1;
	tool = repartiteur(format, ap);
	if (g_worker[(int)'!'] != 1)
		ft_putstr(tool);
	*compteur += ft_strlen(tool);
	if (g_worker[(int)'c'] == 2)
		*compteur += 1;
	free(tool);
}

int		check_leng(char *str)
{
	char	*cur;
	char	count[27];

	cur = str;
	ft_memset(count, 0, 27);
	while (*cur != '%')
	{
		if (*cur >= 'a' && *cur <= 'z')
			count[(int)*cur - 97] += 1;
		cur -= 1;
	}
	if (count[(int)'t' - 97] > 0)
		return ((int)count[(int)'t' - 97] + 40);
	if (count[(int)'z' - 97] > 0)
		return ((int)count[(int)'z' - 97] + 30);
	if (count[(int)'j' - 97] > 0)
		return ((int)count[(int)'j' - 97] + 20);
	if (count[(int)'l' - 97] > 0)
		return ((int)count[(int)'l' - 97] + 10);
	if (count[(int)'h' - 97] > 0)
		return ((int)count[(int)'h' - 97]);
	return (0);
}
