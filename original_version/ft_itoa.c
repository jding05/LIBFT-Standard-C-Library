/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:29:11 by sding             #+#    #+#             */
/*   Updated: 2018/02/28 17:31:07 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_size(int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	is_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	absolute(int n)
{
	if (is_neg(n))
		return (-n);
	return (n);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		neg;

	neg = is_neg(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n = absolute(n);
	size = neg + str_size(n);
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	while (size > 0)
	{
		size--;
		str[size] = absolute(n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
