/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 09:57:10 by sding             #+#    #+#             */
/*   Updated: 2018/06/27 10:21:00 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_copy_table(char **table1, char **table2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (table2[i])
		i++;
	while (j < i)
	{
		table1[j] = table2[j];
		j++;
	}
	table1[j] = 0;
	return (table1);
}
