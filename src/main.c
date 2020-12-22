#include "../includes/ft_printf.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
	r = ft_printf(" %*s %*s ", 1, "123", 10, "4567");
	ft_printf("\n");
	d = printf(" %*s %*s ", 1, "123", 10, "4567");
	printf("\n\nreturn mine is [%d]", r);
	printf("\n\nreturn libc is [%d]", d);
	return (0);
}
