/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:03:45 by sding             #+#    #+#             */
/*   Updated: 2018/03/27 22:04:03 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;
	size_t	i;

	if (!(dst = (char *)malloc(sizeof(char) * n + 1)))
		return (0);
	i = 0;
	while (i < n)
	{
		dst[i] = ((char *)s1)[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
