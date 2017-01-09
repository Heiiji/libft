/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:03:47 by jjuret            #+#    #+#             */
/*   Updated: 2017/01/09 16:11:37 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

int				how_free(char *str)
{
	int count;

	count = 0;
	while (str[count] == ' ' || str[count] == '0')
		count += 1;
	return (count);
}

int				how_free_rev(char *str)
{
	int		count;
	char	*cur;

	count = 0;
	cur = str;
	while (*cur != '\0')
		cur += 1;
	cur -= 1;
	while (*cur == ' ')
	{
		cur -= 1;
		count += 1;
	}
	return (count);
}

static char		*putting_dx(char *str, char ix)
{
	char	*result;
	int		leng;

	leng = (g_worker[(int)'.'] > 0) ? ft_strlen(str) - g_worker[(int)'.'] : 10;
	if (ft_strlen(str) < 1)
		return (str);
	if ((how_free(str) <= 0 && how_free_rev(str) <= 0) || leng < 1)
		return (dx_extend_0(str, ix));
	if (how_free(str) <= 2 && how_free_rev(str) <= 2)
		return (dx_extend_1(str, ix));
	if (how_free_rev(str) > 2)
		return (dx_extend_2(str, ix));
	result = str;
	while (*str == ' ')
		str += 1;
	if (str != result)
	{
		*(str - 1) = ix;
		*(str - 2) = '0';
		return (result);
	}
	*(str + 1) = ix;
	*(str) = '0';
	return (result);
}

char			*process_diese(char **str, va_list *ap)
{
	char	*result;
	char	*tmp;
	char	*cur;

	*str += 1;
	tmp = repartiteur(str, ap);
	cur = tmp;
	if ((*(*str - 1) == 'x' || *(*str - 1) == 'X') && ft_strcmp(tmp, "0") != 0)
		result = putting_dx(tmp, *(*str - 1));
	else
	{
		if ((*(*str - 1) == 'o' || *(*str - 1) == 'O'))
		{
			if (*cur == '\0')
				*cur = '0';
			while (*cur == ' ')
				cur++;
			if (cur != tmp)
				*(cur - 1) = '0';
			else
				tmp = put0(tmp);
		}
		result = tmp;
	}
	return (result);
}

char			*process_neg(char **str, va_list *ap)
{
	char	*nbr;
	char	*cur;
	char	*cur2;

	*str += 1;
	g_worker[(int)'-'] = 1;
	nbr = repartiteur(str, ap);
	cur = nbr;
	cur2 = nbr;
	while (*cur == ' ')
		cur++;
	while (*cur2 != '\0')
	{
		if (*cur != '\0')
		{
			*cur2 = *cur;
			cur++;
		}
		else
			*cur2 = ' ';
		cur2++;
	}
	return (nbr);
}
