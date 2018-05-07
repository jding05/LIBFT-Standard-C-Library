/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:42:33 by sding             #+#    #+#             */
/*   Updated: 2018/04/28 14:44:31 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa_base_uint(uintmax_t nb, uintmax_t base_nb, char c)
{
	char	*result;
	char	*base;
	int		i;

	i = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	if (base_nb < 2 || 16 < base_nb)
		return (NULL);
	result = ft_memalloc(sizeof(char) * 35);
	while (base_nb <= nb)
	{
		result[i++] = base[nb % base_nb];
		nb = nb / base_nb;
	}
	if (base_nb > nb)
		result[i++] = base[nb];
	result[i] = '\0';
	ft_strrev(result);
	return (result);
}
