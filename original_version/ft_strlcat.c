/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 22:51:08 by sding             #+#    #+#             */
/*   Updated: 2018/02/21 22:51:13 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;
	char	*dsrc;

	dsrc = (char *)src;
	src_size = ft_strlen(src);
	dst_size = ft_strlen((const char*)dst);
	i = 0;
	if (dst_size > dstsize)
		return (dstsize + src_size);
	while (src[i] != '\0' && dst_size + i + 1 < dstsize)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst_size + src_size);
}
