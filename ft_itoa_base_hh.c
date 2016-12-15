/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_hh.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:05:46 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/14 15:05:40 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static char	isneg(char *target, char *neg, char base)
{
	if (*target < 0 && base == 10)
	{
		*target = -(*target);
		*neg = 1;
		return (1);
	}
	return (0);
}

static char	leng(unsigned char target, char base)
{
	char	result;

	result = 0;
	while (target > 0)
	{
		target /= base;
		result++;
	}
	return (result);
}

static char	*count(char *result, unsigned char n, char base)
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

char		*ft_itoa_base_hh(char n, char base)
{
	char		*result;
	char		size;
	char		neg;

	neg = 0;
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	size = isneg(&n, &neg, base) + leng((unsigned char)n, base) + 1;
	if ((result = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	result += (size - 1);
	*result = '\0';
	result = count(result, (unsigned char)n, base);
	if (neg == 1 && base == 10)
	{
		result--;
		*result = '-';
	}
	return (result);
}
