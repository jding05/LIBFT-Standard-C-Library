/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:56:20 by sding             #+#    #+#             */
/*   Updated: 2018/04/25 10:56:31 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** flag_space is undefined behavior
** flag_plus is undefined behavior
** flag_zero is undefined behavior
** flag_hash doesn't work
**
** flag_minus works
** field_width work
** length l work with conversion s, corresponds to a pointer to wchar_t argument
*/

int		handle_str(va_list ap, t_arg *arg)
{
	int		arg_len;

	if (arg->length == l)
	{
		arg_len = handle_wstr(ap, arg);
		return (arg_len);
	}
	str_output(ap, arg);
	return (arg->print_count);
}

void	str_output(va_list ap, t_arg *arg)
{
	int		min_print;
	char	*arg_str;
	int		arg_len;

	if ((arg_str = va_arg(ap, char *)) == NULL)
		arg_str = "(null)";
	arg_len = ft_strlen(arg_str);
	min_print = MIN(arg->precision_nb, arg_len);
	(arg->precision == 0) ? min_print = arg_len : 1;
	arg->print_count = min_print;
	str_output_helper(arg, arg_str, min_print, arg_len);
}

void	str_output_helper(t_arg *arg, char *arg_str, int min_print, int arg_len)
{
	if ((arg->precision && arg->field_width == 0) || arg->width_nb < min_print)
		ft_putnstr(arg_str, arg->print_count);
	else if (arg->field_width == 1 || arg->width_nb > min_print)
	{
		if (arg->flag_minus)
		{
			ft_putnstr(arg_str, min_print);
			print_padded_char(arg->width_nb - min_print, arg, ' ');
		}
		else
		{
			print_padded_char(arg->width_nb - min_print, arg, ' ');
			ft_putnstr(arg_str, min_print);
		}
	}
	else
	{
		ft_putstr(arg_str);
		arg->print_count += arg_len;
	}
}
