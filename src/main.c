#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
	r = ft_printf("%%*.s%10.4s", "1");
	ft_printf("\n");
	d = printf("%%*.s%10.4s", "1");

	printf("\nme  return %d\n", r);
	printf("lib return %d\n", d);
	return (0);
}
