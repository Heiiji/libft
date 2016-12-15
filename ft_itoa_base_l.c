/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:35:05 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/14 14:59:00 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static long int	isneg(long int *target, long int *neg, long int base)
{
	if (*target < 0 && base == 10)
	{
		*target = -(*target);
		*neg = 1;
		return (1);
	}
	return (0);
}

static long int	leng(unsigned long int target, long int base)
{
	long int	result;

	result = 0;
	while (target > 0)
	{
		target /= base;
		result++;
	}
	return (result);
}

static char		*count(char *result, unsigned long int n, long int base)
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

char			*ft_itoa_base_l(long int n, long int base)
{
	char			*result;
	long int		size;
	long int		neg;

	neg = 0;
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	size = isneg(&n, &neg, base) + leng((unsigned long int)n, base) + 1;
	if ((result = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	result += (size - 1);
	*result = '\0';
	result = count(result, (unsigned long int)n, base);
	if (neg == 1 && base == 10)
	{
		result--;
		*result = '-';
	}
	return (result);
}
