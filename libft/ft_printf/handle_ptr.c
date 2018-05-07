/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:20:00 by sding             #+#    #+#             */
/*   Updated: 2018/04/27 13:20:02 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** flag_hash has no effect
** flag_minus override flag_zero
** flag_plus override flag_spacea
** flag_space undefined behavior, doesn't work
** flag_plus undefined bahavior, doesn't work
** flag_zero undefined behaviior, doesn't work
**
** flag_minus works
** width_nb should be at least 15, below 15 doenst have any effect
** precision work, but belongs to undefined behavior
*/

int		handle_ptr(va_list ap, t_arg *arg)
{
	uintmax_t	arg_address_nb;
	char		*address_str;
	int			arg_len;

	arg_address_nb = (uintmax_t)va_arg(ap, void*);
	address_str = ft_itoa_base_uint(arg_address_nb, 16, 'x');
	arg_len = ft_strlen(address_str);
	arg->print_count += arg_len;
	if (arg->flag_minus == 0)
		ptr_output1(address_str, arg, arg_len);
	if (arg->flag_minus == 1)
		ptr_output2(address_str, arg, arg_len);
	free(address_str);
	return (arg->print_count);
}

void	ptr_output1(char *address_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	pad_space_nb = MAX(arg->width_nb - arg_len - 2, 0);
	pad_zero_nb = MAX(arg->precision_nb - arg_len, 0);
	if (pad_space_nb > 0 || pad_zero_nb > 0)
	{
		if (pad_zero_nb >= pad_space_nb)
		{
			print_hex_flag_hash(arg);
			print_padded_char(pad_zero_nb, arg, '0');
		}
		if (pad_zero_nb < pad_space_nb)
		{
			print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
			print_hex_flag_hash(arg);
			print_padded_char(pad_zero_nb, arg, '0');
		}
	}
	else
		print_hex_flag_hash(arg);
	ft_putstr(address_str);
}

void	ptr_output2(char *address_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	pad_space_nb = MAX(arg->width_nb - arg_len - 2, 0);
	pad_zero_nb = MAX(arg->precision_nb - arg_len, 0);
	print_hex_flag_hash(arg);
	if (pad_space_nb > 0 || pad_zero_nb > 0)
	{
		if (pad_zero_nb >= pad_space_nb)
		{
			print_padded_char(pad_zero_nb, arg, '0');
			ft_putstr(address_str);
		}
		if (pad_zero_nb < pad_space_nb)
		{
			print_padded_char(pad_zero_nb, arg, '0');
			ft_putstr(address_str);
			print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
		}
	}
	else
		ft_putstr(address_str);
}
