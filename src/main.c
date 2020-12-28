#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
	r = ft_printf("%07d", -54);
	ft_printf("\n");
	d = printf("%07d", -54);

	printf("\nme  return %d\n", r);
	printf("lib return %d\n", d);
	return (0);
}
