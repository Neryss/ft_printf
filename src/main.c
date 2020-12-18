#include "../includes/ft_printf.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	// printf("test\n");
	// ft_printf("c is : %12c\nand %0c\nand %-23c yeah\n", 'j', 'r', 'y');
	// printf("c is : %12c\nand %0c\nand %-23c yeah\n", 'j', 'r', 'y');
	// ft_printf("mine\n [%0*c] oy\n [%0*c] eheh\n", 10, 'c', 6, 'j');
	// printf("printf\n [%0*c] oy\n [%0*c] eheh\n", 10, 'c', 6, 'j');
	ft_printf("%*c\0 0",50,'m');
	//printf("\n\nreturn libc is [%d]", d);
	return (0);
}
