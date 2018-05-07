/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:34:59 by sding             #+#    #+#             */
/*   Updated: 2018/04/30 12:50:09 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	check_new_line(int fd, char **store, char **line)
{
	char	*tmp;
	size_t	len;

	if (ft_strchr(store[fd], '\n') == NULL)
	{
		*line = ft_strdup(store[fd]);
		free(store[fd]);
		store[fd] = NULL;
	}
	else
	{
		len = ft_strlen_til(store[fd], '\n');
		*line = ft_strndup(store[fd], len);
		tmp = ft_strdup(store[fd] + len + 1);
		free(store[fd]);
		if (tmp)
		{
			store[fd] = ft_strdup(tmp);
			free(tmp);
		}
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[GNL_BUFF_SIZE + 1];
	int			nb_read;
	static char	*store[1024];
	char		*tmp;

	CHECK((fd < 0 || !line || GNL_BUFF_SIZE < 1 || read(fd, buf, 0) < 0), -1);
	if (!store[fd])
		store[fd] = ft_strnew(0);
	while (ft_strchr(store[fd], '\n') == NULL)
	{
		if (!(nb_read = read(fd, buf, GNL_BUFF_SIZE)))
			break ;
		buf[nb_read] = '\0';
		tmp = ft_strjoin(store[fd], buf);
		free(store[fd]);
		if (!(store[fd] = ft_strdup(tmp)))
			store[fd] = ft_strnew(0);
		free(tmp);
	}
	CHECK(((nb_read == 0 && store[fd] == NULL) || store[fd][0] == '\0'), 0);
	return (check_new_line(fd, store, line));
}
