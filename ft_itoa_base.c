/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:43:09 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/14 15:00:18 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static int	isneg(int *target, int *neg, int base)
{
	if (*target < 0 && base == 10)
	{
		*target = -(*target);
		*neg = 1;
		return (1);
	}
	return (0);
}

static int	leng(unsigned int target, int base)
{
	int	result;

	result = 0;
	while (target > 0)
	{
		target /= base;
		result++;
	}
	return (result);
}

static char	*count(char *result, unsigned int n, int base)
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

char		*ft_itoa_base(int n, int base)
{
	char	*result;
	int		size;
	int		neg;

	neg = 0;
	if (n == -2147483648 && base <= 10)
		return (ft_strdup("-2147483648"));
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	size = isneg(&n, &neg, base) + leng((unsigned int)n, base) + 1;
	if ((result = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	result += (size - 1);
	*result = '\0';
	result = count(result, (unsigned int)n, base);
	if (neg == 1 && base == 10)
	{
		result--;
		*result = '-';
	}
	return (result);
}
