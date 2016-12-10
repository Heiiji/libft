/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:21:22 by jjuret            #+#    #+#             */
/*   Updated: 2016/12/10 13:09:29 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>

typedef char*	(*t_action)(char **str, va_list *ap);
int				ft_printf(const char *format, ...);
void			print_action(char **format, va_list *ap, int *compteur);
int				check_leng(char *str);
char			*repartiteur(char **str, va_list *ap);
char			*process_u(char **str, va_list *ap);
char			*process_d(char **str, va_list *ap);
char			*process_ld(char **str, va_list *ap);
char			*process_o(char **str, va_list *ap);
char			*process_lo(char **str, va_list *ap);
char			*process_x(char **str, va_list *ap);
char			*process_lx(char **str, va_list *ap);
char			*process_0(char **str, va_list *ap);
char			*process_0_bis(char *tmp, char *work);
char			*process_nbr(char **str, va_list *ap);
char			*process_s(char **str, va_list *ap);
char			*process_ls(char **str, va_list *ap);
char			*process_c(char **str, va_list *ap);
char			*process_lc(char **str, va_list *ap);
char			*process_percent(char **str, va_list *ap);
char			*process_pos(char **str, va_list *ap);
char			*process_pos_bis(char *render, char *nbr);
int				how_free_rev(char *str);
char			*process_dot(char **str, va_list *ap);
char			*process_dot_bis(char *cur, char *result, \
				int precision, char **str);
char			*process_l(char **str, va_list *ap);
char			*process_space(char **str, va_list *ap);
char			*process_lld(char **str, va_list *ap);
char			*process_llx(char **str, va_list *ap);
int				how_free(char *str);
int				how_free_rev(char *str);
char			*process_diese(char **str, va_list *ap);
char			*put0(char *base);
char			*process_neg(char **str, va_list *ap);
char			*dx_extend_0(char *str, char ix);
char			*dx_extend_1(char *str, char ix);
char			*dx_extend_2(char *str, char ix);
t_action		g_print_tools[255];
int				g_worker[255];

#endif
