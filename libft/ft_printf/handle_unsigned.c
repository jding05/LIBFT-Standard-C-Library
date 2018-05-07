/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 22:12:13 by sding             #+#    #+#             */
/*   Updated: 2018/04/27 22:12:22 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** flag_hash doesn't work
** if precision is given, flag_zero is ignored
** flag_minus is override flag_zero
** flag_space undefined behavior
** flag_plus undefined behavior
**
** flag_minus works
*/

int		handle_unsigned(va_list ap, t_arg *arg)
{
	uintmax_t	nb;
	char		*unsigned_str;
	int			arg_len;

	nb = get_unsigned_type_by_length(ap, arg);
	unsigned_str = ft_itoa_base_uint(nb, 10, arg->conversion);
	arg_len = ft_strlen(unsigned_str);
	arg->print_count += arg_len;
	if (arg->flag_minus == 0 && arg->flag_zero == 0)
		unsigned_output1(unsigned_str, arg, arg_len);
	else if (arg->flag_minus == 1)
		unsigned_output2(unsigned_str, arg, arg_len);
	else if (arg->flag_zero == 1)
		unsigned_output3(unsigned_str, arg, arg_len);
	free(unsigned_str);
	return (arg->print_count);
}

void	unsigned_output1(char *unsigned_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	pad_space_nb = MAX(arg->width_nb - arg_len, 0);
	pad_zero_nb = MAX(arg->precision_nb - arg_len, 0);
	if (pad_space_nb > 0 || pad_zero_nb > 0)
	{
		if (pad_zero_nb < pad_space_nb)
			print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
		print_padded_char(pad_zero_nb, arg, '0');
	}
	ft_putstr(unsigned_str);
}

void	unsigned_output2(char *unsigned_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	pad_space_nb = MAX(arg->width_nb - arg_len, 0);
	pad_zero_nb = MAX(arg->width_nb - arg_len, 0);
	print_padded_char(pad_zero_nb - pad_space_nb, arg, '0');
	ft_putstr(unsigned_str);
	print_padded_char(pad_space_nb, arg, ' ');
}

void	unsigned_output3(char *unsigned_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_zero_nb;

	pad_zero_nb = MAX(arg->width_nb - arg_len, 0);
	print_padded_char(pad_zero_nb, arg, '0');
	ft_putstr(unsigned_str);
}
