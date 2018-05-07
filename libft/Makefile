# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sding <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 20:34:27 by sding             #+#    #+#              #
#    Updated: 2018/04/10 17:28:02 by sding            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

CC			:=	gcc
CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -I includes

FT_LIBC		:=	ft_memset ft_bzero ft_memcpy  ft_memccpy ft_memmove ft_memchr	\
				ft_memcmp ft_strlen ft_strdup ft_strndup ft_strcpy ft_strncpy	\
				ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr	\
				ft_strnstr ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit	\
				ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower
	  

FT_ADD_ON	:=	ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter	\
				ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub	\
				ft_strjoin ft_strtrim ft_strsplit ft_itoa ft_putchar ft_putstr	\
				ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd	\
				ft_putnbr_fd

LST			:=	ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap	\
				ft_lstaddtoend

FT_EXTRA	:=	ft_count_words ft_malloc_word ft_strrev ft_search_and_replace	\
				ft_swap ft_realloc ft_check_repeat ft_print_table ft_free_table	\
				ft_putstrl ft_putnbrl ft_putcharl ft_strlen_til ft_putstr_db	\
				ft_putnstr ft_putnbr_intmax_t ft_nbrlen ft_putwchar ft_putwstr	\
				ft_wstrlen ft_putnwstr ft_itoa_base_uint ft_putnbr_uintmax_t

GNL			:=	get_next_line

FT_PRINTF	:=	dispatch_table ft_printf handle_int handle_char	ft_printf_parse	\
				handle_wchar handle_str handle_wstr handle_hex handle_ptr		\
				handle_octal handle_unsigned handle_escape get_int_type 		\
				ft_printf_initial_print


FILES		:=	$(addprefix ft_libc/, $(FT_LIBC))		\
				$(addprefix ft_add_on/, $(FT_ADD_ON))	\
				$(addprefix lst/, $(LST))				\
				$(addprefix ft_extra/, $(FT_EXTRA))		\
				$(addprefix gnl/, $(GNL))				\
				$(addprefix ft_printf/, $(FT_PRINTF))	\

SRC			:=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ			:=	$(SRC:.c=.o)


.PHONY = all clean fclean re

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[32mCompiled Library\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mRemoved Library\033[0m"

re: fclean all
