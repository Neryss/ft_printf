#include "../includes/ft_printf.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
	r = ft_printf(" 0*%0-*x*0 0*%0*x*0 ", 21, 1021, 21, -1011);
	ft_printf("\n");
	// ft_printf("%10.21x|", 134);
	d = printf(" 0*%0-*x*0 0*%0*x*0 ", 21, 1021, 21, -1011);
	// printf("%10.21x|", -101);
	// printf("%10.21x|", 134);
	printf("\n");
	// printf("%10.21x", 134);

	printf("\n\nreturn mine is [%d]", r);
	printf("\n\nreturn libc is [%d]", d);
	return (0);
}
