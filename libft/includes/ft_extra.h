/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:21:54 by sding             #+#    #+#             */
/*   Updated: 2018/06/27 10:20:29 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXTRA_H
# define FT_EXTRA_H

# include "libft.h"

int		    ft_check_repeat(char *str, char c);
int		    ft_count_words(char const *str, char c);
void	    ft_free_table(char **table);
char	    *ft_itoa_base_uint(uintmax_t nb, uintmax_t base_nb, char c);
char		*ft_malloc_word(char const *str, char c);
size_t		ft_nbrlen(size_t nb);
void	    ft_print_table(char **table);
void		ft_putcharl(char c);
void		ft_putnbr_intmax_t(intmax_t n);
void		ft_putnbr_uintmax_t(uintmax_t n);
void		ft_putnbrl(int n);
void	    ft_putnstr(char *str, size_t n);
void	    ft_putnwstr(wchar_t *wstr, size_t n);
void		ft_putstr_db(char const *s, char *str);
void		ft_putstrl(char const *s);
void	    ft_putwchar(wchar_t c);
void	    ft_putwstr(wchar_t *wstr);
void	    *ft_realloc(void *ptr, size_t src_size, size_t new_size);
void	    ft_search_and_replace(char *d, char a, char b);
int		    ft_strlen_til(char *str, char c);
char		*ft_strrev(char *str);
void	    ft_swap(int *a, int *b);
size_t	    ft_wstrlen(wchar_t *wstr);

int			ft_is_delim(char c, char *delims);
int			ft_count_words_by_delims(char const *str, char *delims);
char		*ft_malloc_word_by_delims(char const *str, char *delims);
char		**ft_strsplit_by_delims(char const *s, char *delims);
char		**ft_copy_table(char **table1, char **table2);
char		**ft_dbarray_merge(char **dbarray1, char **dbarray2);

#endif
