/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:43:13 by sding             #+#    #+#             */
/*   Updated: 2018/04/29 23:00:39 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

/*
** colorize ANSI Colors
*/

# define BLACK		"\033[0;30m"
# define BLUE		"\033[0;34m"
# define CYAN		"\033[1;36m"
# define DARKYELLOW	"\033[0;33m"
# define GREEN		"\033[0;32m"
# define GREY		"\033[1;30m"
# define LAVENDER	"\033[1;35m"
# define LIGHTBLUE	"\033[0;36m"
# define LIGHTGREY	"\033[0;37m"
# define LIME		"\033[1;32m"
# define MAGENTA	"\033[0;35m"
# define PINK		"\033[1;31m"
# define PURPLE		"\033[1;34m"
# define RED		"\033[0;31m"
# define UNDERLINE	"\033[4m"
# define WHITE		"\033[1;37m"
# define YELLOW		"\033[1;33m"
# define RESET		"\033[0m"

/*
** Underline
*/

# define UBLACK "\033[4;30m"
# define URED "\033[4;31m"
# define UGREEN "\033[4;32m"
# define UYELLOW "\033[4;33m"
# define UBLUE "\033[4;34m"
# define UPURPLE "\033[4;35m"
# define UCYAN "\033[4;36m"
# define UWHITE "\033[4;37m"

/*
** things to store 1. flag, field-width, precision, length
** enumeration (or enum) is a user defined data type in c
**		it is mainly used to assign names to integral constants
*/

typedef struct	s_arg
{
	int			flag_hash;
	int			flag_zero;
	int			flag_minus;
	int			flag_space;
	int			flag_plus;
	int			field_width;
	int			width_nb;
	int			precision;
	int			precision_nb;
	enum		{null, h, hh, l, ll, j, z} length;
	char		conversion;
	int			print_count;
	int			neg_arg_int;
}				t_arg;

typedef	int		(*t_func)(va_list, t_arg *);

/*
** dispatch_table.c
*/

int				dptable_get_handler(char **format, va_list ap, t_arg *arg);

/*
** ft_printf.c
*/

int				solve_arg(char **format, va_list ap, t_arg *sarg);
int				ft_solve_format(char *format, va_list ap, size_t chars);
int				ft_printf(const char *format, ...);

/*
** parse.c
*/

char			*ft_printf_parse_flag(char **format, t_arg *arg);
char			*ft_printf_parse_width(char **format, t_arg *arg, va_list ap);
char			*ft_printf_parse_length(char **format, t_arg *arg);
char			*ft_printf_parse_conversion(char **format, t_arg *arg);
char			*ft_printf_parse_prescision(char **format, t_arg *arg,
																	va_list ap);

/*
** initial_print.c
*/

void			initial(t_arg *arg);
void			print_struct(t_arg *arg);
void			print_padded_char(int padded_len, t_arg *arg, char c);
void			print_int_sign(t_arg *arg);

/*
** handle_int.c
*/

int				handle_int(va_list ap, t_arg *arg);
void			int_output1(intmax_t nb, t_arg *arg, int arg_len);
void			int_output2(intmax_t nb, t_arg *arg, int arg_len);
void			int_output3(intmax_t nb, t_arg *arg, int arg_len);
int				int_output_helper(t_arg *arg, intmax_t nb, int arg_len);

/*
** handle_char.c
*/

int				handle_char(va_list ap, t_arg *arg);

/*
** handle_wchar.c
*/

int				handle_wchar(va_list ap, t_arg *arg);

/*
** handle_str.c
*/

int				handle_str(va_list ap, t_arg *arg);
void			str_output(va_list ap, t_arg *arg);
void			str_output_helper(t_arg *arg, char *arg_str, int min_print,
															int arg_len);

/*
** handle_wstr.c
*/

int				handle_wstr(va_list ap, t_arg *arg);
void			wstr_output(t_arg *arg, wchar_t *arg_wstr, int arg_len,
															int min_print);

/*
** handle_hex.c
*/

char			*ft_itoa_base_uint(uintmax_t nb, uintmax_t base_nb, char c);
void			print_hex_flag_hash(t_arg *arg);
void			hex_output1(char *hex_str, t_arg *arg, int arg_len);
void			hex_output2(char *hex_str, t_arg *arg, int arg_len);
void			hex_output3(char *hex_str, t_arg *arg, int arg_len);
int				handle_hex(va_list ap, t_arg *arg);
void			hex_helper(char *hex_str, t_arg *arg, int arg_len);

/*
** handle_ptr.c
*/

void			ptr_output1(char *address_str, t_arg *arg, int arg_len);
void			ptr_output2(char *address_str, t_arg *arg, int arg_len);
int				handle_ptr(va_list ap, t_arg *arg);

/*
** handle_oct.c
*/

void			oct_output1(char *oct_str, t_arg *arg, int arg_len);
void			oct_output2(char *oct_str, t_arg *arg, int arg_len);
void			oct_output3(char *oct_str, t_arg *arg, int arg_len);
int				handle_octal(va_list ap, t_arg *arg);
void			oct_output_helper(char *oct_str, t_arg *arg, int arg_len);

/*
** handle_unsigned.c
*/

void			unsigned_output1(char *unsigned_str, t_arg *arg, int arg_len);
void			unsigned_output2(char *unsigned_str, t_arg *arg, int arg_len);
void			unsigned_output3(char *unsigned_str, t_arg *arg, int arg_len);
int				handle_unsigned(va_list ap, t_arg *arg);

/*
** handle_escape.c
*/

int				handle_escape(va_list ap, t_arg *arg);

/*
** get_int_type.c
*/

uintmax_t		get_unsigned_type_by_length(va_list ap, t_arg *arg);
intmax_t		get_int_type_by_length(va_list ap, t_arg *arg);

#endif
