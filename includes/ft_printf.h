/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:02:59 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/21 14:48:47 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# define ARGUMENTS "cspdiuxX"

typedef struct t_element
{
	int		left_justify;
	int		zero;
	int		sign;
	int		width;
	int		field;
	int		dot;
	int		dot_size;
	char	type;
	int		star;
}				s_element;

int		ft_printf(const char *, ...);
int		print_width(s_element *elem, int len);
int		check_flags(const char *str, s_element *elem, va_list valist);
int		check_minus(const char *str, s_element *elem);
int		check_zero(const char *str, s_element *elem);
int		check_star(const char *str, s_element *elem);
int		check_dot(const char *str, s_element *elem);
int		is_dot_first(const char *str);
int		get_memberlen(const char *str, s_element *elem, int i);
int		ft_print_p(s_element *elem, int nb);
int		special_atoi(const char *str);
void	init_struct(s_element *elem);
void	debug_struct(s_element *elem);
int		ft_print_char(s_element *elem, va_list valist);
int		ft_print_str(s_element *elem, char *str);
int		select_parsing(va_list valist, s_element *elem);

#endif