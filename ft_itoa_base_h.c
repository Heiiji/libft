/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_h.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:22:37 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/14 15:05:24 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static short int	isneg(short int *target, short int *neg, short int base)
{
	if (*target < 0 && base == 10)
	{
		*target = -(*target);
		*neg = 1;
		return (1);
	}
	return (0);
}

static short int	leng(unsigned short int target, short int base)
{
	short int	result;

	result = 0;
	while (target > 0)
	{
		target /= base;
		result++;
	}
	return (result);
}

static char			*count(char *result, unsigned short int n, short int base)
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

char				*ft_itoa_base_h(short int n, short int base)
{
	char			*result;
	short int		size;
	short int		neg;

	neg = 0;
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	size = isneg(&n, &neg, base) + leng((unsigned short int)n, base) + 1;
	if ((result = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	result += (size - 1);
	*result = '\0';
	result = count(result, (unsigned short int)n, base);
	if (neg == 1 && base == 10)
	{
		result--;
		*result = '-';
	}
	return (result);
}
