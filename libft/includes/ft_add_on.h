/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_on.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:00:26 by sding             #+#    #+#             */
/*   Updated: 2018/05/01 17:00:27 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADD_ON_H
# define FT_ADD_ON_H

#include "libft.h"

char		*ft_itoa(int n);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putendl(char const *s);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr(int n);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putstr(char const *s);
void		ft_strclr(char *s);
void		ft_strdel(char **as);
int			ft_strequ(char const *s1, char const *s2);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strnew(size_t size);
char		**ft_strsplit(char const *s, char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);

#endif
