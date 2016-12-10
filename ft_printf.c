/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:37:54 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/10 13:13:04 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

char			*repartiteur(char **str, va_list *ap)
{
	char	*matcher;

	while (**str == 'l' || **str == 'h' || **str == 'z' || **str == 'j')
		*str += 1;
	if (g_print_tools[(int)**str] != 0)
		matcher = g_print_tools[(int)**str](str, ap);
	else
		return (ft_strdup("\0"));
	return (matcher);
}

static void		init_tools2(void)
{
	g_print_tools[(int)'0'] = &process_0;
	g_print_tools[(int)'1'] = &process_nbr;
	g_print_tools[(int)'2'] = &process_nbr;
	g_print_tools[(int)'3'] = &process_nbr;
	g_print_tools[(int)'4'] = &process_nbr;
	g_print_tools[(int)'5'] = &process_nbr;
	g_print_tools[(int)'6'] = &process_nbr;
	g_print_tools[(int)'7'] = &process_nbr;
	g_print_tools[(int)'8'] = &process_nbr;
	g_print_tools[(int)'9'] = &process_nbr;
	g_print_tools[(int)'#'] = &process_diese;
}

static void		init_tools(void)
{
	ft_memset(g_print_tools, 0, 255);
	g_print_tools[(int)'L'] = &process_l;
	g_print_tools[(int)'l'] = &process_l;
	g_print_tools[(int)'d'] = &process_d;
	g_print_tools[(int)'i'] = &process_d;
	g_print_tools[(int)'D'] = &process_ld;
	g_print_tools[(int)'u'] = &process_u;
	g_print_tools[(int)'U'] = &process_u;
	g_print_tools[(int)'o'] = &process_o;
	g_print_tools[(int)'O'] = &process_lo;
	g_print_tools[(int)'x'] = &process_x;
	g_print_tools[(int)'X'] = &process_lx;
	g_print_tools[(int)'+'] = &process_pos;
	g_print_tools[(int)'-'] = &process_neg;
	g_print_tools[(int)' '] = &process_space;
	g_print_tools[(int)'.'] = &process_dot;
	g_print_tools[(int)'%'] = &process_percent;
	g_print_tools[(int)'s'] = &process_s;
	g_print_tools[(int)'S'] = &process_ls;
	g_print_tools[(int)'c'] = &process_c;
	g_print_tools[(int)'C'] = &process_lc;
	g_print_tools[(int)'p'] = &process_s;
	init_tools2();
}

int				ft_printf(const char *format, ...)
{
	int		curseur;
	int		compteur;
	va_list ap;

	curseur = 0;
	compteur = 0;
	va_start(ap, format);
	init_tools();
	while (*format != '\0')
	{
		if (*format == '%')
			print_action((char**)&format, &ap, &compteur);
		else
		{
			ft_putchar(*format);
			compteur++;
			format += 1;
		}
	}
	return (compteur);
}
