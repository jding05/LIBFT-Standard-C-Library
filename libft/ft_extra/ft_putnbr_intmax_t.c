/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_intmax_t.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:26:44 by sding             #+#    #+#             */
/*   Updated: 2018/04/19 15:26:46 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** need to add ft_putchar('-') under if (n < 0); later
*/

void		ft_putnbr_intmax_t(intmax_t n)
{
	if (n < 0)
		ft_putnbr_uintmax_t(-n);
	else if (n >= 10)
	{
		ft_putnbr_intmax_t(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
}
