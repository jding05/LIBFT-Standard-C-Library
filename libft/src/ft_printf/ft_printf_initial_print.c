/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:21:00 by sding             #+#    #+#             */
/*   Updated: 2018/04/28 16:14:53 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	initial(t_arg *arg)
{
	arg->flag_hash = 0;
	arg->flag_zero = 0;
	arg->flag_minus = 0;
	arg->flag_space = 0;
	arg->flag_plus = 0;
	arg->field_width = 0;
	arg->width_nb = 0;
	arg->precision = 0;
	arg->precision_nb = 0;
	arg->conversion = 0;
	arg->print_count = 0;
	arg->neg_arg_int = 0;
}

void	print_struct(t_arg *arg)
{
	ft_putstr("\narg->flag_hash	 :");
	ft_putnbrl(arg->flag_hash);
	ft_putstr("arg->flag_zero	 :");
	ft_putnbrl(arg->flag_zero);
	ft_putstr("arg->flag_minus	 :");
	ft_putnbrl(arg->flag_minus);
	ft_putstr("arg->flag_space	 :");
	ft_putnbrl(arg->flag_space);
	ft_putstr("arg->flag_plus	 :");
	ft_putnbrl(arg->flag_plus);
	ft_putstr("arg->field_width :");
	ft_putnbrl(arg->field_width);
	ft_putstr("arg->width_nb	 :");
	ft_putnbrl(arg->width_nb);
	ft_putstr("arg->precision	 :");
	ft_putnbrl(arg->precision);
	ft_putstr("arg->precision_nb:");
	ft_putnbrl(arg->precision_nb);
	ft_putstr("arg->conversion	 :");
	ft_putcharl(arg->conversion);
	ft_putstr("arg->print_count :");
	ft_putnbrl(arg->print_count);
	ft_putstr("arg->neg_arg_int :");
	ft_putnbrl(arg->neg_arg_int);
	ft_putstrl("------------------------------------");
}

void	print_int_sign(t_arg *arg)
{
	if ((arg->flag_plus || arg->flag_space) && arg->neg_arg_int == 0)
	{
		if (arg->flag_plus)
		{
			write(1, "+", 1);
			arg->print_count++;
		}
		else if (arg->flag_space)
		{
			write(1, " ", 1);
			arg->print_count++;
		}
	}
	if (arg->neg_arg_int)
	{
		write(1, "-", 1);
		arg->print_count++;
	}
}

void	print_padded_char(int padded_len, t_arg *arg, char c)
{
	int	i;

	i = 0;
	while (i < padded_len)
	{
		ft_putchar(c);
		arg->print_count++;
		i++;
	}
}

void	print_hex_flag_hash(t_arg *arg)
{
	if (arg->conversion == 'x' || arg->conversion == 'p')
	{
		write(1, "0x", 2);
		arg->print_count += 2;
	}
	else if (arg->conversion == 'X')
	{
		write(1, "0X", 2);
		arg->print_count += 2;
	}
	else if (arg->conversion == 'o' || arg->conversion == 'O')
	{
		write(1, "0", 1);
		arg->print_count++;
	}
}
