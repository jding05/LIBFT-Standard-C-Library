/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:37:44 by sding             #+#    #+#             */
/*   Updated: 2018/05/01 16:37:45 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_parse_flag(char **format, t_arg *arg)
{
	if (**format == '#' || **format == '0' || **format == '-' ||
		**format == ' ' || **format == '+')
	{
		while (**format == '#' || **format == '0' || **format == '-' ||
				**format == ' ' || **format == '+')
		{
			if (**format == '#')
				arg->flag_hash = 1;
			else if (**format == '0')
				arg->flag_zero = 1;
			else if (**format == '-')
				arg->flag_minus = 1;
			else if (**format == ' ')
				arg->flag_space = 1;
			else if (**format == '+')
				arg->flag_plus = 1;
			if (arg->flag_minus)
				arg->flag_zero = 0;
			if (arg->flag_plus)
				arg->flag_space = 0;
			(*format)++;
		}
	}
	return (*format);
}

char	*ft_printf_parse_width(char **format, t_arg *arg, va_list ap)
{
	int	int_arg;

	while (**format == '*' || ft_isdigit(**format))
	{
		arg->field_width = 1;
		if (**format == '*')
		{
			if ((int_arg = va_arg(ap, int)) < 0)
			{
				arg->flag_minus = 1;
				arg->width_nb = -int_arg;
			}
			else
				arg->width_nb = int_arg;
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			while (ft_isdigit(**format))
				arg->width_nb = arg->width_nb * 10 + *(*format)++ - '0';
		}
	}
	return (*format);
}

char	*ft_printf_parse_prescision(char **format, t_arg *arg, va_list ap)
{
	int	int_prec;

	if (**format == '.')
	{
		(*format)++;
		arg->precision = 1;
		if (**format == '*')
		{
			if ((int_prec = va_arg(ap, int)) >= 0)
				arg->precision_nb = int_prec;
			else
			{
				arg->precision = 0;
				arg->field_width = 1;
				arg->width_nb = -int_prec;
			}
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			while (ft_isdigit(**format))
				arg->precision_nb = arg->precision_nb * 10 + *(*format)++ - '0';
		}
	}
	return (*format);
}

char	*ft_printf_parse_length(char **format, t_arg *arg)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		arg->length = hh;
		return (*format += 2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		arg->length = ll;
		return (*format += 2);
	}
	else if (**format == 'h' || **format == 'l' || **format == 'j' ||
		**format == 't' || **format == 'z' || **format == 'q')
	{
		if (**format == 'h')
			arg->length = h;
		else if (**format == 'l')
			arg->length = l;
		else if (**format == 'j')
			arg->length = j;
		else if (**format == 'z')
			arg->length = z;
		return ((*format)++);
	}
	else
		return (*format);
}

char	*ft_printf_parse_conversion(char **format, t_arg *arg)
{
	if (**format == 's' || **format == 'S' || **format == 'p' || **format == 'd'
	|| **format == 'D' || **format == 'i' || **format == 'o' || **format == 'O'
	|| **format == 'u' || **format == 'U' || **format == 'x' || **format == 'X'
	|| **format == 'c' || **format == 'C' || **format == '%')
	{
		arg->conversion = **format;
		(*format)++;
	}
	return (*format);
}
