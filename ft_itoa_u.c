/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heiji <heiji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:30:29 by heiji             #+#    #+#             */
/*   Updated: 2016/12/01 16:12:39 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static unsigned int	leng(unsigned int target)
{
	unsigned int	result;

	result = 0;
	while (target > 0)
	{
		target /= 10;
		result++;
	}
	return (result);
}

static char			*count(char *result, unsigned int n)
{
	while (n > 0)
	{
		result--;
		*result = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}

char				*ft_itoa_u(unsigned int n)
{
	char				*result;
	unsigned int		size;

	if (n == 0)
		return (ft_strdup("0"));
	size = leng(n) + 1;
	if ((result = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	result += (size - 1);
	*result = '\0';
	result = count(result, n);
	return (result);
}
