#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
	r = ft_printf("[ %3% ]");
	ft_printf("\n");
	d = printf("[ %3% ]");

	printf("\nme  return %d\n", r);
	printf("lib return %d\n", d);
	return (0);
}
