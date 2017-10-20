# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 08:54:13 by jjuret            #+#    #+#              #
#    Updated: 2017/10/20 08:54:20 by jjuret           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a

SRC =	./ft_atoi.c\
		./ft_bzero.c\
		./ft_count_words.c\
		./ft_display_file.c\
		./ft_foreach.c\
		./ft_isalnum.c\
		./ft_isalpha.c\
		./ft_isascii.c\
		./ft_isdigit.c\
		./ft_isprint.c\
		./ft_itoa.c\
		./ft_itoa_l.c\
		./ft_itoa_u.c\
		./ft_itoa_base_l.c\
		./ft_itoa_base_h.c\
		./ft_itoa_base_hh.c\
		./ft_lstadd.c\
		./ft_lstdel.c\
		./ft_lstdelone.c\
		./ft_lstiter.c\
		./ft_lstmap.c\
		./ft_lstnew.c\
		./ft_memalloc.c\
		./ft_memccpy.c\
		./ft_memchr.c\
		./ft_memcmp.c\
		./ft_memcpy.c\
		./ft_memdel.c\
		./ft_memmove.c\
		./ft_memset.c\
		./ft_putchar_fd.c\
		./ft_putchar.c\
		./ft_putwchar.c\
		./ft_putwchar_fd.c\
		./ft_putendl_fd.c\
		./ft_putendl.c\
		./ft_putnbr_fd.c\
		./ft_putnbr.c\
		./ft_putnbr_u.c\
		./ft_putstr_fd.c\
		./ft_putstr.c\
		./ft_putwstr.c\
		./ft_putnwstr.c\
		./ft_putwstr_fd.c\
		./ft_sqrt.c\
		./ft_strcat.c\
		./ft_strchr.c\
		./ft_strclr.c\
		./ft_strcmp.c\
		./ft_strcpy.c\
		./ft_strdel.c\
		./ft_strdup.c\
		./ft_strequ.c\
		./ft_striter.c\
		./ft_striteri.c\
		./ft_strjoin.c\
		./ft_strlcat.c\
		./ft_strlen.c\
		./ft_wstrlen.c\
		./ft_strmap.c\
		./ft_strmapi.c\
		./ft_strncat.c\
		./ft_strncpy.c\
		./ft_strncmp.c\
		./ft_strnequ.c\
		./ft_strnew.c\
		./ft_strnstr.c\
		./ft_strrchr.c\
		./ft_strsplit.c\
		./ft_strstr.c\
		./ft_strsub.c\
		./ft_strtrim.c\
		./ft_swap.c\
		./ft_tolower.c\
		./ft_toupper.c\
		./ft_printf.c\
		./ft_print_process.c\
		./ft_print_process2.c\
		./ft_print_process3.c\
		./ft_print_process4.c\
		./ft_print_process5.c\
		./ft_print_process6.c\
		./ft_print_miniprocess.c\
		./ft_print_miniprocess2.c\
		./ft_itoa_base.c\
		./ft_itoa_base_ll.c\
		./ft_itoa_base_ull.c\
		./ft_power.c\
		./get_next_line.c

OBJS =  $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o    :    %.c $(DEPENDS)
	@gcc -Wall -Werror -Wextra -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
