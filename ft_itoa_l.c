/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:15:26 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/01 12:49:28 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static long int	isneg(long int *target, long int *neg)
{
	if (*target < 0)
	{
		*target = -(*target);
		*neg = 1;
		return (1);
	}
	return (0);
}

static long int	leng(long int target)
{
	long int	result;

	result = 0;
	while (target > 0)
	{
		target /= 10;
		result++;
	}
	return (result);
}

static char		*count(char *result, long int n)
{
	while (n > 0)
	{
		result--;
		*result = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}

char			*ft_itoa_l(long int n)
{
	char			*result;
	long int		size;
	long int		neg;

	neg = 0;
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	size = isneg(&n, &neg) + leng(n) + 1;
	if ((result = (char *)malloc(sizeof(char) * (int)size)) == NULL)
		return (NULL);
	result += (size - 1);
	*result = '\0';
	result = count(result, n);
	if (neg == 1)
	{
		result--;
		*result = '-';
	}
	return (result);
}
