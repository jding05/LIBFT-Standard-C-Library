/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 23:00:57 by sding             #+#    #+#             */
/*   Updated: 2018/02/22 23:01:28 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	new_c;
	size_t			i;

	str = (unsigned char *)s;
	new_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(str + i) == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}
