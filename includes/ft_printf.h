/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:02:59 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/16 17:31:56 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>


typedef struct t_element
{
	int		left_justify;
	int		zero;
	int		sign;
	int		width;
	int		field;
	int		period;
	char	type;
}				s_element;

int		ft_printf(const char *, ...);
int		print_width(int width, int has_zero);
void	init_struct(s_element *elem);
int		ft_parse_char(const char *str, s_element *elem, va_list valist);
int		select_parsing(va_list valist, const char *str, s_element *elem);
int		check_flags(const char *str, s_element *elem, va_list valist);

#endif