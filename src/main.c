#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int		a = -4;
	int		b = 0;
	int		d = 2147483647;
	char	c = 'a';
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*r = "%%";
	char	*p = "-12";

	int eheh, oui = 0;
	eheh = ft_printf("%-*.*x", 4, 0, 8);
	ft_printf("\n");
	oui = printf("%-*.*x", 4, 0, 8);

	printf("\nme  return %d\n", eheh);
	printf("lib return %d\n", oui);
	return (0);
}
