#include "../includes/ft_printf.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
	// r = ft_printf(" %5.1s ", "salut");
	// ft_printf("\n");
	// d = printf(" %5.1s ", "salut");
	r = ft_printf(" %-15p ", 112343);
	ft_printf("\n");
	d = printf(" %-15p ", 112343);
	printf("\n\nreturn mine is [%d]", r);
	printf("\n\nreturn libc is [%d]", d);
	return (0);
}
