# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 08:54:13 by jjuret            #+#    #+#              #
#    Updated: 2016/12/15 17:30:08 by jjuret           ###   ########.fr        #
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
		./ft_power.c\
		./get_next_line.c

OBJS = ./ft_atoi.o\
		./ft_bzero.o\
		./ft_count_words.o\
		./ft_display_file.o\
		./ft_foreach.o\
		./ft_isalnum.o\
		./ft_isalpha.o\
		./ft_isascii.o\
		./ft_isdigit.o\
		./ft_isprint.o\
		./ft_itoa.o\
		./ft_itoa_l.o\
		./ft_itoa_u.o\
		./ft_itoa_base_l.o\
		./ft_itoa_base_h.o\
		./ft_itoa_base_hh.o\
		./ft_lstadd.o\
		./ft_lstdel.o\
		./ft_lstdelone.o\
		./ft_lstiter.o\
		./ft_lstmap.o\
		./ft_lstnew.o\
		./ft_memalloc.o\
		./ft_memccpy.o\
		./ft_memchr.o\
		./ft_memcmp.o\
		./ft_memcpy.o\
		./ft_strdel.o\
		./ft_memdel.o\
		./ft_memmove.o\
		./ft_memset.o\
		./ft_putchar_fd.o\
		./ft_putchar.o\
		./ft_putwchar.o\
		./ft_putwchar_fd.o\
		./ft_putendl_fd.o\
		./ft_putendl.o\
		./ft_putnbr_fd.o\
		./ft_putnbr.o\
		./ft_putnbr_u.o\
		./ft_putstr_fd.o\
		./ft_putstr.o\
		./ft_putwstr.o\
		./ft_putwstr_fd.o\
		./ft_sqrt.o\
		./ft_strcat.o\
		./ft_strchr.o\
		./ft_strclr.o\
		./ft_strcmp.o\
		./ft_strnequ.o\
		./ft_strcpy.o\
		./ft_strdup.o\
		./ft_strequ.o\
		./ft_striter.o\
		./ft_striteri.o\
		./ft_strjoin.o\
		./ft_strlcat.o\
		./ft_strlen.o\
		./ft_wstrlen.o\
		./ft_strmap.o\
		./ft_strmapi.o\
		./ft_strncat.o\
		./ft_strncmp.o\
		./ft_strncpy.o\
		./ft_strnew.o\
		./ft_strnstr.o\
		./ft_strrchr.o\
		./ft_strsplit.o\
		./ft_strstr.o\
		./ft_strsub.o\
		./ft_strtrim.o\
		./ft_swap.o\
		./ft_tolower.o\
		./ft_toupper.o\
		./ft_printf.o\
		./ft_print_process.o\
		./ft_print_process2.o\
		./ft_print_process3.o\
		./ft_print_process4.o\
		./ft_print_process5.o\
		./ft_print_process6.o\
		./ft_print_miniprocess.o\
		./ft_print_miniprocess2.o\
		./ft_itoa_base.o\
		./ft_itoa_base_ll.o\
		./ft_power.o\
		./get_next_line.o

all:$(NAME)

$(NAME):
	gcc -c $^ $(SRC) -Wall -Werror -Wextra
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
