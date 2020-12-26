/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:48:52 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/26 15:41:26 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	print_di_else(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (elem->dot)
	{
		if (elem->dot_size > len)
		{

			if (str[0] == '-')
			{
				elem->zero = 0;
				i += print_width(elem, elem->dot_size + 1);
				i += ft_putchar('-');
				i += print_zero(elem->dot_size - len + 1);
				i += ft_putstrl(str + 1, len);
			}
			else
			{
				elem->zero = 0;
				i += print_width(elem, elem->dot_size);
				i += print_zero(elem->dot_size - len);
				i += ft_putstrl(str, len);
			}
		}
		else
		{
			if (len == 1 && str[1] == 0)
			{
				i += print_width(elem, elem->dot_size);
				i += ft_putstrl(str, elem->dot_size);
			}
			else
			{
				elem->zero = 0;
				i += print_width(elem, len);
				i += ft_putstr(str);
			}
		}
	}
	else
	{
		if (str[0] == '-')
		{
			i += ft_putchar('-');
			i += print_width(elem, len);
			i += ft_putstr(str + 1 );
		}
		else
		{
			i += print_width(elem, len);
			i += ft_putstr(str);
		}
	}
	return (i);
}

static	int	print_di_justify(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (elem->dot)
	{
		if (elem->dot_size > len)
		{
			if (str[0] == '-')
			{
				i += ft_putchar('-');
				i += print_zero(elem->dot_size - len + 1);
				i += ft_putstrl(str + 1, elem->dot_size);
				i += print_width(elem, elem->dot_size + 1);
			}
			else
			{
				i += print_zero(elem->dot_size - len);
				i += ft_putstr(str);
				i += print_width(elem, elem->dot_size);
			}
		}
		else
		{
			if (len == 1 && str[1] == 0)
			{
				i += ft_putstrl(str, elem->dot_size);
				i += print_width(elem, elem->dot_size);
			}
			else
			{
				i += ft_putstr(str);
				i += print_width(elem, len);
			}
		}
		
	}
	else
	{
		if (str[0] == '-')
		{
			i += ft_putchar('-');
			i += ft_putstr(str + 1 );
			i += print_width(elem, len);
		}
		i += ft_putstr(str);
		i += print_width(elem, len);
	}
	return (i);
}

// int			print_negative(char *str, int len)
// {
	 
// }

int			ft_print_di(t_element *elem, int nb)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	str = ft_itoa(nb);
	len = ft_strlen(str);
	if (elem->left_justify)
		i += print_di_justify(elem, str, len);
	else
		i += print_di_else(elem, str, len);
	return (i);
}