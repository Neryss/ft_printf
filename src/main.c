#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
	r = ft_printf("|%d|", 2348);
	ft_printf("\n");
	d = printf("|%d|", 2348);

	printf("\n\nreturn mine is [%d]", r);
	printf("\n\nreturn libc is [%d]", d);
	return (0);
}
