/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:07:21 by sding             #+#    #+#             */
/*   Updated: 2018/04/28 13:07:34 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnwstr(wchar_t *wstr, size_t n)
{
	if (!wstr)
		return ;
	if (ft_wstrlen(wstr) >= n)
		write(1, wstr, n);
	else
		return ;
}
