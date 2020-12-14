/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:02:03 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/14 17:25:10 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_ischarset(char c, const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_arg(va_list valist, const char *str)
{
	str++;
	if (*str == 'c')
		ft_putchar(va_arg(valist, int));
	return (1);
}

size_t	get_wlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	char	*buff;

	va_start(args, str);
	
	while (*str)
	{
		buff = ft_strndup(str, get_wlen(str));
		printf("%s\n", buff);
		if (*str == '%')
		{
			get_arg(args, str);
			str++;
		}
		ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (1);
}

int main(void)
{
	printf("test\n");
	ft_printf("c is : %c\n%c\n%c\n", 'a', 'b', 'c');
	return (0);
}