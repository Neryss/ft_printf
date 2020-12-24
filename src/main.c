#include "../includes/ft_printf.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
	r = ft_printf(" 0*%-0*.x*0 ", 21, -0);
	ft_printf("\n");
	d = printf(" 0*%-0*.x*0 ", 21, -0);

	printf("\n\nreturn mine is [%d]", r);
	printf("\n\nreturn libc is [%d]", d);
	return (0);
}
