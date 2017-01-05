/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:01:54 by jjuret            #+#    #+#             */
/*   Updated: 2017/01/05 11:25:48 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static unsigned long long int	leng(unsigned long long int target, \
	unsigned long long int base)
{
	unsigned long long int	result;

	result = 0;
	while (target > 0)
	{
		target /= base;
		result++;
	}
	return (result);
}

static char						*count(char *result, unsigned long long int n, \
	unsigned long long int base)
{
	while (n > 0)
	{
		result--;
		*result = (n % base);
		if (*result > 9)
			*result += 87;
		else
			*result += 48;
		n /= base;
	}
	return (result);
}

char							*ft_itoa_base_ull(unsigned long long int n,\
								unsigned long long int base)
{
	char						*result;
	unsigned long long int		size;
	unsigned long long int		neg;

	neg = 0;
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	size = leng((unsigned long long int)n, base) + 1;
	if ((result = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	result += (size - 1);
	*result = '\0';
	result = count(result, (unsigned long long int)n, base);
	if (neg == 1 && base == 10)
	{
		result--;
		*result = '-';
	}
	return (result);
}
