/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:45:38 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/05 12:51:25 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static long long int	isneg(long long int *target, long long int *neg, \
	long long int base)
{
	if (*target < 0 && base <= 10)
	{
		*target = -(*target);
		*neg = 1;
		return (1);
	}
	return (0);
}

static long long int	leng(unsigned long long int target, long long int base)
{
	long long int	result;

	result = 0;
	while (target > 0)
	{
		target /= base;
		result++;
	}
	return (result);
}

static char				*count(char *result, unsigned long long int n, \
	long long int base)
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

char					*ft_itoa_base_ll(long long int n, long long int base)
{
	char				*result;
	long long int		size;
	long long int		neg;

	neg = 0;
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	size = isneg(&n, &neg, base) + leng((unsigned long long int)n, base) + 1;
	if ((result = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	result += (size - 1);
	*result = '\0';
	result = count(result, (unsigned long long int)n, base);
	if (neg == 1 && base <= 10)
	{
		result--;
		*result = '-';
	}
	return (result);
}
