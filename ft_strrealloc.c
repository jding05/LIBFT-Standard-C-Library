/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:02:23 by sding             #+#    #+#             */
/*   Updated: 2018/04/04 12:02:54 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *memory, size_t size)
{
	char	*bigger_memory;

	if (!memory)
	{
		bigger_memory = ft_strnew(size);
		return (bigger_memory);
	}
	bigger_memory = ft_memalloc(ft_strlen(memory) + size);
	return (bigger_memory);
}

/*
** for the ft_strdel(&memory) == free(memory)
*/
