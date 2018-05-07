/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:46:44 by sding             #+#    #+#             */
/*   Updated: 2018/04/18 16:46:45 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	create_dispatch_table(t_func *id)
{
	id['s'] = &handle_str;
	id['S'] = &handle_wstr;
	id['p'] = &handle_ptr;
	id['d'] = &handle_int;
	id['D'] = &handle_int;
	id['i'] = &handle_int;
	id['o'] = &handle_octal;
	id['O'] = &handle_octal;
	id['u'] = &handle_unsigned;
	id['U'] = &handle_unsigned;
	id['x'] = &handle_hex;
	id['X'] = &handle_hex;
	id['c'] = &handle_char;
	id['C'] = &handle_wchar;
	id['%'] = &handle_escape;
}

int			dptable_get_handler(char **format, va_list ap, t_arg *arg)
{
	char			c;
	static t_func	handlers[128] = {NULL};

	ft_printf_parse_conversion(format, arg);
	c = arg->conversion;
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		create_dispatch_table(handlers);
	else
	{
		c = **format;
		if (c == '+' || c == '-' || c == '0' || c == ' ' || c == '#' ||
			c == '.' || c == 'h' || c == 'l' || c == 'j' || c == 'z')
			return (-1);
		else
			return (0);
	}
	return (handlers[(int)c](ap, arg));
}
