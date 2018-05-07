/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:02:01 by sding             #+#    #+#             */
/*   Updated: 2018/04/25 18:02:03 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		handle_wstr(va_list ap, t_arg *arg)
{
	wchar_t	*arg_wstr;
	int		arg_len;
	int		min_print;

	arg_wstr = va_arg(ap, wchar_t *);
	arg_len = ft_wstrlen(arg_wstr);
	min_print = MIN(arg->precision_nb, arg_len);
	wstr_output(arg, arg_wstr, arg_len, min_print);
	return (arg->print_count);
}

void	wstr_output(t_arg *arg, wchar_t *arg_wstr, int arg_len, int min_print)
{
	if ((arg->precision && arg->field_width == 0) || arg->width_nb < min_print)
	{
		arg->print_count += min_print;
		ft_putnwstr(arg_wstr, arg->print_count);
	}
	else if (arg->field_width == 1 || arg->width_nb > min_print)
	{
		if (arg->flag_minus)
		{
			ft_putnwstr(arg_wstr, min_print);
			print_padded_char(arg->field_width - min_print, arg, ' ');
		}
		else
		{
			print_padded_char(arg->field_width - min_print, arg, ' ');
			ft_putnwstr(arg_wstr, min_print);
		}
		arg->print_count += min_print;
	}
	else
	{
		ft_putwstr(arg_wstr);
		arg->print_count += arg_len;
	}
}
