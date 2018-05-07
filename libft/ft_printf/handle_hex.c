/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:59:37 by sding             #+#    #+#             */
/*   Updated: 2018/04/26 16:00:15 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		hex_output1(char *hex_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	if (arg->flag_hash)
		pad_space_nb = MAX(arg->width_nb - arg_len - 2, 0);
	else
		pad_space_nb = MAX(arg->width_nb - arg_len, 0);
	pad_zero_nb = MAX(arg->precision_nb - arg_len, 0);
	if (arg->flag_hash && (pad_zero_nb >= pad_space_nb))
		print_hex_flag_hash(arg);
	if (pad_space_nb > 0 || pad_zero_nb > 0)
	{
		if (pad_zero_nb < pad_space_nb)
		{
			if (arg->flag_hash)
			{
				print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
				print_hex_flag_hash(arg);
			}
			else
				print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
		}
		print_padded_char(pad_zero_nb, arg, '0');
	}
	ft_putstr(hex_str);
}

/*
**flag_minus == 1, precision still work
*/

void		hex_output2(char *hex_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	if (arg->flag_hash)
	{
		pad_space_nb = MAX(arg->width_nb - arg_len - 2, 0);
		print_hex_flag_hash(arg);
	}
	else
		pad_space_nb = MAX(arg->width_nb - arg_len, 0);
	pad_zero_nb = MAX(arg->width_nb - arg_len - 2, 0);
	print_padded_char(pad_zero_nb - pad_space_nb, arg, '0');
	ft_putstr(hex_str);
	print_padded_char(pad_space_nb, arg, ' ');
}

void		hex_output3(char *hex_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_zero_nb;

	if (arg->flag_hash)
	{
		pad_zero_nb = MAX(arg->width_nb - arg_len - 2, 0);
		print_hex_flag_hash(arg);
	}
	else
		pad_zero_nb = MAX(arg->width_nb - arg_len, 0);
	print_padded_char(pad_zero_nb, arg, '0');
	ft_putstr(hex_str);
}

/*
** flag_space is undefined behavior
** flag_plus is undefined behavior
**
** flag_zero works
** if precision == 1, flag_zero doesn't works, flag_minus doesn't work
** flag_minus works
** field_width works
*/

int			handle_hex(va_list ap, t_arg *arg)
{
	uintmax_t	nb;
	char		*hex_str;
	int			arg_len;

	if (arg->precision || arg->flag_minus)
		arg->flag_zero = 0;
	if ((nb = get_unsigned_type_by_length(ap, arg)) == 0)
		arg->flag_hash = 0;
	hex_str = ft_itoa_base_uint(nb, 16, arg->conversion);
	arg_len = ft_strlen(hex_str);
	if (arg->flag_minus == 0 && arg->flag_zero == 0)
	{
		if (arg->precision == 1 && arg->precision_nb == 0)
		{
			if (arg->width_nb)
				print_padded_char(arg->width_nb, arg, ' ');
			free(hex_str);
			return (arg->print_count);
		}
		hex_output1(hex_str, arg, arg_len);
	}
	else if (arg->flag_minus == 1 || arg->flag_zero == 1)
		hex_helper(hex_str, arg, arg_len);
	free(hex_str);
	return (arg->print_count + arg_len);
}

void		hex_helper(char *hex_str, t_arg *arg, int arg_len)
{
	if (arg->flag_minus == 1)
		hex_output2(hex_str, arg, arg_len);
	else if (arg->flag_zero == 1)
		hex_output3(hex_str, arg, arg_len);
}
