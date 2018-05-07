/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:12:06 by sding             #+#    #+#             */
/*   Updated: 2018/04/29 22:12:08 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

intmax_t	get_int_type_by_length(va_list ap, t_arg *arg)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	if (arg->length == h && arg->conversion != 'D')
		nb = (short int)nb;
	else if (arg->length == l || arg->conversion == 'D')
		nb = (long int)nb;
	else if (arg->length == hh)
		nb = (signed char)nb;
	else if (arg->length == ll)
		nb = (long long int)nb;
	else if (arg->length == j)
		nb = (intmax_t)nb;
	else if (arg->length == z)
		nb = (size_t)nb;
	else
		nb = (int)nb;
	return (nb);
}

uintmax_t	get_unsigned_type_by_length(va_list ap, t_arg *arg)
{
	uintmax_t	nb;

	nb = va_arg(ap, intmax_t);
	if (arg->length == h && arg->conversion != 'U' && arg->conversion != 'O')
		nb = (unsigned short int)nb;
	else if (arg->length == l || arg->conversion == 'U' ||
			arg->conversion == 'O')
		nb = (unsigned long int)nb;
	else if (arg->length == hh)
		nb = (unsigned char)nb;
	else if (arg->length == ll)
		nb = (unsigned long long int)nb;
	else if (arg->length == j)
		nb = (uintmax_t)nb;
	else if (arg->length == z)
		nb = (size_t)nb;
	else
		nb = (unsigned int)nb;
	return (nb);
}
