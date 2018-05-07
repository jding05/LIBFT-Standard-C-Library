/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:30:57 by sding             #+#    #+#             */
/*   Updated: 2018/04/27 16:31:13 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** flag_space is undefined behavior
** flag_plus is undefined behavior
** flag_minus override flag_zero
**
** flag_minus works
** field_width works
*/

void	oct_output1(char *oct_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	pad_space_nb = MAX(arg->width_nb - arg_len, 0);
	if (arg->flag_hash)
		pad_space_nb = MAX(arg->width_nb - arg_len - 1, 0);
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
	ft_putstr(oct_str);
}

void	oct_output2(char *oct_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	if (arg->flag_hash)
	{
		pad_space_nb = MAX(arg->width_nb - arg_len - 1, 0);
		print_hex_flag_hash(arg);
		pad_zero_nb = MAX(arg->precision_nb - arg_len - 1, 0);
	}
	else
	{
		pad_space_nb = MAX(arg->width_nb - arg_len, 0);
		pad_zero_nb = MAX(arg->precision_nb - arg_len, 0);
	}
	if (pad_zero_nb >= pad_space_nb)
	{
		print_padded_char(pad_zero_nb, arg, '0');
		ft_putstr(oct_str);
	}
	else
	{
		print_padded_char(pad_zero_nb, arg, '0');
		ft_putstr(oct_str);
		print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
	}
}

void	oct_output3(char *oct_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_zero_nb;

	if (arg->flag_hash)
	{
		pad_zero_nb = MAX(arg->width_nb - arg_len - 1, 0);
		print_hex_flag_hash(arg);
	}
	else
		pad_zero_nb = MAX(arg->width_nb - arg_len, 0);
	print_padded_char(pad_zero_nb, arg, '0');
	ft_putstr(oct_str);
}

int		handle_octal(va_list ap, t_arg *arg)
{
	uintmax_t	nb;
	char		*oct_str;
	int			arg_len;

	nb = get_unsigned_type_by_length(ap, arg);
	oct_str = ft_itoa_base_uint(nb, 8, arg->conversion);
	arg_len = ft_strlen(oct_str);
	if (arg->flag_minus == 0 && arg->flag_zero == 0)
	{
		if (arg->precision == 1 && arg->precision_nb == 0)
		{
			if (arg->width_nb)
				print_padded_char(arg->width_nb, arg, ' ');
			if (arg->flag_hash)
				print_hex_flag_hash(arg);
			free(oct_str);
			return (arg->print_count);
		}
		(nb == 0 && arg->flag_hash == 1) ? arg->flag_hash = 0 : 1;
		oct_output1(oct_str, arg, arg_len);
	}
	else if (arg->flag_minus == 1 || arg->flag_zero == 1)
		oct_output_helper(oct_str, arg, arg_len);
	free(oct_str);
	return (arg->print_count + arg_len);
}

void	oct_output_helper(char *oct_str, t_arg *arg, int arg_len)
{
	if (arg->flag_minus == 1)
		oct_output2(oct_str, arg, arg_len);
	else if (arg->flag_zero == 1)
		oct_output3(oct_str, arg, arg_len);
}
