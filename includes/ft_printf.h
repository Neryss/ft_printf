/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:02:59 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/18 17:05:08 by ckurt            ###   ########lyon.fr   */
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
	char	type;
	int		star;
}				s_element;

int		ft_printf(const char *, ...);
int		print_width(s_element *elem);
int		check_flags(const char *str, s_element *elem, va_list valist);
int		check_minus(const char *str, s_element *elem);
int		check_zero(const char *str, s_element *elem);
int		check_star_dot(char **str, s_element *elem);
int		get_memberlen(const char *str, s_element *elem, int i);
int		check_min_zero(char **str, s_element *elem);
int		special_atoi(const char *str);
int		get_minus_len(const char *str, int i);
int		get_elem_len(const char *str, int i);
void	init_struct(s_element *elem);
void	debug_struct(s_element *elem);
int		ft_parse_char(const char *str, s_element *elem, va_list valist);
int		select_parsing(va_list valist, const char *str, s_element *elem);

#endif