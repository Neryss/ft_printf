#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
	r = ft_printf(" %-3.2d %10.42d ", 1, -1);
	ft_printf("\n");
	d = printf(" %-3.2d %10.42d ", 1, -1);

	return (0);
}
