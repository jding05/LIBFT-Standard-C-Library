/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 23:54:50 by sding             #+#    #+#             */
/*   Updated: 2018/04/27 23:55:05 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** flag_space did nothing
** flag_plus doesn't work
** flag_hash doesn't work
**
** flag_minus works
** width_nb works
*/

int		handle_escape(va_list ap, t_arg *arg)
{
	(void)ap;
	if (arg->flag_minus)
	{
		ft_putchar('%');
		print_padded_char(arg->width_nb - 1, arg, ' ');
	}
	else
	{
		if (arg->flag_zero)
			print_padded_char(arg->width_nb - 1, arg, '0');
		else
		{
			print_padded_char(arg->width_nb - 1, arg, ' ');
		}
		ft_putchar('%');
	}
	return (arg->print_count + 1);
}
