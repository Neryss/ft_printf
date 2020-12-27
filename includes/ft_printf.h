/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:02:59 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/27 13:05:38 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# define ARGUMENTS "cspdiuxX%"

typedef	struct	s_element
{
	int			left_justify;
	int			zero;
	int			sign;
	int			width;
	int			field;
	int			dot;
	int			dot_size;
	char		type;
	int			star;
}				t_element;

int				ft_printf(const char *str, ...);
int				print_width(t_element *elem, int len);
int				check_flags(const char *str, t_element *elem, va_list valist);
int				check_minus(const char *str, t_element *elem);
int				check_zero(const char *str, t_element *elem);
int				check_star(const char *str, t_element *elem, va_list valist);
int				check_dot(const char *str, t_element *elem);
int				is_dot_first(const char *str);
int				get_memberlen(const char *str, t_element *elem, int i);
int				special_atoi(const char *str);
void			init_struct(t_element *elem);
void			debug_struct(t_element *elem);
int				ft_print_char(t_element *elem, va_list valist);
int				ft_print_percent(t_element *elem);
int				ft_print_str(t_element *elem, char *str);
int				ft_print_p(t_element *elem, size_t nb);
int				ft_print_x(t_element *elem, unsigned int nb, char *base);
int				ft_print_di(t_element *elem, int nb);
int				ft_print_u(t_element *elem, unsigned int nb);
int				dot_else_justif(t_element *elem, char *str, int len);
int				dot_size_greater_justif(t_element *elem, char *str, int len);
int				print_zero(int len);
int				select_parsing(va_list valist, t_element *elem);

#endif
