/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:46:44 by sding             #+#    #+#             */
/*   Updated: 2018/04/25 21:46:45 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		handle_wchar(va_list ap, t_arg *arg)
{
	wchar_t		wc;

	wc = va_arg(ap, wchar_t);
	if (arg->flag_minus)
	{
		ft_putwchar(wc);
		print_padded_char(arg->field_width - 1, arg, ' ');
	}
	else
	{
		print_padded_char(arg->field_width - 1, arg, ' ');
		ft_putwchar(wc);
	}
	return (arg->print_count + 1);
}
