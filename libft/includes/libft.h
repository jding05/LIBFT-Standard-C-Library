/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 16:17:00 by sding             #+#    #+#             */
/*   Updated: 2018/04/10 17:28:39 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "ft_libc.h"
# include "ft_add_on.h"
# include "lst.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define CHECK(x, y)if(x)return(y)
# define MAX(x, y) x > y ? x : y
# define MIN(x, y) x < y ? x : y

#endif
