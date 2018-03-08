/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:49:08 by sding             #+#    #+#             */
/*   Updated: 2018/02/22 14:49:11 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	size_t	i;

	str = dst;
	i = 0;
	while (i < n)
	{
		*(str + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}
