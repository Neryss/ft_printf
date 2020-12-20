#include "../includes/ft_printf.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
	// r = ft_printf("%*c0\n",50,'m');
	// d = printf("%*c0\n",50,'m');
	r = ft_printf(" %*.4s %.4s ", 10, "123", "4567");
	ft_printf("\n");
	d = printf(" %*.4s %.4s ", 10, "123", "4567");
	printf("\n\nreturn mine is [%d]", r);
	printf("\n\nreturn libc is [%d]", d);
	return (0);
}
