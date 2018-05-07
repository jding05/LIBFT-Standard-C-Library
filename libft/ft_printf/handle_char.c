/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:06:04 by sding             #+#    #+#             */
/*   Updated: 2018/04/25 10:06:07 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** flag_space doesn't work with conversion c (undefined behavior)
** flag_plus doesn't work with conversion c (undefined behavior)
** flag_hash doesn't work with conversion c
** precision is undefined behavior also precision_nb not work
** flag_zero doesn't work with conversion c
**
** flag_minus work with conversion c
** field_width work
*/

int		handle_char(va_list ap, t_arg *arg)
{
	char	c;

	if (arg->length == l)
	{
		arg->print_count = handle_wchar(ap, arg);
		return (arg->print_count);
	}
	c = va_arg(ap, int);
	if (arg->flag_minus)
	{
		ft_putchar(c);
		print_padded_char(arg->width_nb - 1, arg, ' ');
	}
	else
	{
		if (arg->flag_zero)
			print_padded_char(arg->width_nb - 1, arg, '0');
		else
			print_padded_char(arg->width_nb - 1, arg, ' ');
		ft_putchar(c);
	}
	return (arg->print_count + 1);
}
