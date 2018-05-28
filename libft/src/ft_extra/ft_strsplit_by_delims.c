/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_by_delims.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:04:27 by sding             #+#    #+#             */
/*   Updated: 2018/05/28 16:09:34 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_is_delim(char c, char *delims)
{
	while (*delims && c)
	{
		if (c == *delims)
			return (1);
		++delims;
	}
	return (0);
}

int		ft_count_words_by_delims(char const *str, char *delims)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		while (*str && ft_is_delim(*str, delims))
			str++;
		if (*str && !ft_is_delim(*str, delims))
		{
			count++;
			while (*str && !ft_is_delim(*str, delims))
				str++;
		}
	}
	return (count);
}

char		*ft_malloc_word_by_delims(char const *str, char *delims)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !ft_is_delim(str[i], delims))
		i++;
	word = (char *)ft_memalloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_is_delim(str[i], delims))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char		**ft_strsplit_by_delims(char const *s, char *delims)
{
	int		words;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	words = ft_count_words_by_delims(s, delims);
	tab = (char **)ft_memalloc(sizeof(char*) * (words + 1));
	i = 0;
	while (*s)
	{
		while (*s && ft_is_delim(*s, delims))
			s++;
		if (*s && !ft_is_delim(*s, delims))
		{
			tab[i] = ft_malloc_word_by_delims(s, delims);
			i++;
			while (*s && !ft_is_delim(*s, delims))
				s++;
		}
	}
	tab[i] = 0;
	return (tab);
}
