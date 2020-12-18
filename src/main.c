#include "../includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int r;
	int d;

	r = 0;
	d = 0;
	// printf("test\n");
	// ft_printf("c is : %12c\nand %0c\nand %-23c yeah\n", 'j', 'r', 'y');
	// printf("c is : %12c\nand %0c\nand %-23c yeah\n", 'j', 'r', 'y');
	// ft_printf("mine\n [%0*c] oy\n [%0*c] eheh\n", 10, 'c', 6, 'j');
	// printf("printf\n [%0*c] oy\n [%0*c] eheh\n", 10, 'c', 6, 'j');
	r = ft_printf("%c", '0');
	printf("\n");
	d = printf("%c", '0');
	printf("\n\nreturn is [%d]", r);
	printf("\n\nreturn libc is [%d]", d);
	return (0);
}