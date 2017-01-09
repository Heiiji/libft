/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:50:49 by jjuret            #+#    #+#             */
/*   Updated: 2017/01/09 14:23:17 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

char			*process_u(char **str, va_list *ap)
{
	char	*result;
	char	drole[2];

	*str += 1;
	result = NULL;
	drole[1] = '\0';
	g_worker[(int)'+'] = -1;
	if (check_leng(*str) == 11 || *(*str - 1) == 'U')
		result = ft_itoa_base_ull(va_arg(*ap, long unsigned int), 10);
	if (check_leng(*str) == 12 && *(*str - 1) != 'U')
		result = ft_itoa_base_ull(va_arg(*ap, long long unsigned int), 10);
	if (check_leng(*str) == 1 && *(*str - 1) != 'U')
		result = ft_itoa_base((unsigned short)va_arg(*ap, int), 10);
	if (check_leng(*str) == 2 && *(*str - 1) != 'U')
		result = ft_itoa((int)((unsigned char)va_arg(*ap, int)));
	if (check_leng(*str) == 21 && *(*str - 1) != 'U')
		result = ft_itoa_base_ull(va_arg(*ap, long long unsigned int), 10);
	if (check_leng(*str) == 31 && *(*str - 1) != 'U')
		result = ft_itoa_base_ull(va_arg(*ap, long long unsigned int), 10);
	if (result == NULL)
		result = ft_itoa_base_l(va_arg(*ap, unsigned int), 10);
	return (result);
}

char			*process_d(char **str, va_list *ap)
{
	short int	nbr;

	*str += 1;
	if (check_leng(*str) == 12)
		return (ft_itoa_base_ll(va_arg(*ap, long long int), 10));
	if (check_leng(*str) == 11)
		return (ft_itoa_base_l(va_arg(*ap, long int), 10));
	if (check_leng(*str) == 21)
		return (ft_itoa_base_l(va_arg(*ap, long long int), 10));
	if (check_leng(*str) == 31)
		return (ft_itoa_base_l(va_arg(*ap, size_t), 10));
	if (check_leng(*str) == 2)
		return (ft_itoa_base_hh((char)va_arg(*ap, int), 10));
	if (check_leng(*str) == 1)
	{
		nbr = (short int)va_arg(*ap, int);
		return (ft_itoa_base(nbr, 10));
	}
	return (ft_itoa(va_arg(*ap, int)));
}

char			*process_ld(char **str, va_list *ap)
{
	*str += 1;
	return (ft_itoa_base_l(va_arg(*ap, long int), 10));
}

char			*process_o(char **str, va_list *ap)
{
	int	nbr;

	*str += 1;
	g_worker[(int)'o'] = 1;
	if (check_leng(*str) == 31)
		return (ft_itoa_base_l(va_arg(*ap, size_t), 8));
	if (check_leng(*str) == 12)
		return (ft_itoa_base_ll(va_arg(*ap, long long int), 8));
	if (check_leng(*str) == 11 || *(*str - 1) == 'O')
		return (ft_itoa_base_l(va_arg(*ap, long int), 8));
	if (check_leng(*str) == 21)
		return (ft_itoa_base_ll(va_arg(*ap, long long int), 8));
	if (check_leng(*str) == 1)
		return (ft_itoa_base_h(va_arg(*ap, int), 8));
	if (check_leng(*str) == 2)
	{
		nbr = va_arg(*ap, int);
		return (ft_itoa_base_hh((short int)nbr, 8));
	}
	return (ft_itoa_base(va_arg(*ap, int), 8));
}

char			*process_lo(char **str, va_list *ap)
{
	*str += 1;
	return (ft_itoa_base_l(va_arg(*ap, long int), 8));
}
