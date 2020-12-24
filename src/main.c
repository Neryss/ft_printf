#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
	r = ft_printf("%09.0x", UINT_MAX);
	ft_printf("\n");
	d = printf("%09.0x", UINT_MAX);

	printf("\n\nreturn mine is [%d]", r);
	printf("\n\nreturn libc is [%d]", d);
	return (0);
}
