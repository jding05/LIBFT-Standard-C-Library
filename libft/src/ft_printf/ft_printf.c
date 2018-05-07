/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:45:36 by sding             #+#    #+#             */
/*   Updated: 2018/04/17 11:45:39 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		solve_arg(char **format, va_list ap, t_arg *arg)
{
	int		nb_printout;

	initial(arg);
	nb_printout = 0;
	if (**format == '\0')
		return (0);
	while (**format)
	{
		if ((ft_printf_parse_flag(format, arg)) == NULL)
			return (-1);
		if ((ft_printf_parse_width(format, arg, ap)) == NULL)
			return (-1);
		if ((ft_printf_parse_prescision(format, arg, ap)) == NULL)
			return (-1);
		if ((ft_printf_parse_length(format, arg)) == NULL)
			return (-1);
		if ((nb_printout = dptable_get_handler(format, ap, arg)) >= 0)
			break ;
	}
	return (nb_printout);
}

int		ft_solve_format(char *format, va_list ap, size_t chars)
{
	t_arg	arg;
	char	*next_arg;
	int		arg_printout;

	if (!*format)
		return (chars);
	if (!(next_arg = ft_strchr(format, '%')))
	{
		ft_putstr(format);
		return (chars + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, next_arg - format);
		return (ft_solve_format(next_arg, ap, chars + (next_arg - format)));
	}
	else
	{
		format++;
		if ((arg_printout = solve_arg((char **)&format, ap, &arg)) == -1)
			return (-1);
		return (ft_solve_format(format, ap, chars + arg_printout));
	}
	return (arg_printout);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		result;

	va_start(arg_ptr, format);
	result = ft_solve_format((char*)format, arg_ptr, 0);
	va_end(arg_ptr);
	return (result);
}
