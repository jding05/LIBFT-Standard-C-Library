/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbarray_merge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:14:11 by sding             #+#    #+#             */
/*   Updated: 2018/06/27 10:22:26 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_dbarray_merge(char **dbarray1, char **dbarray2)
{
	int		i;
	int		j;
	int		k;
	char	**dbarray;

	i = 0;
	j = 0;
	k = 0;
	while (dbarray1[i])
		i++;
	while (dbarray2[j])
		j++;
	k = i + j - 1;
	j = 0;
	dbarray = (char **)ft_memalloc(sizeof(char) * k);
	while (j < k)
	{
		dbarray[j] = ft_strdup(dbarray1[j]);
		j++;
	}
	i = 0;
	while (j < k)
		dbarray[j++] = ft_strdup(dbarray2[i++]);
	ft_free_table(dbarray1);
	ft_free_table(dbarray2);
	return (dbarray);
}	
