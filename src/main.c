#include "../includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("test\n");
	// ft_printf("c is : %12c\nand %0c\nand %-23c yeah\n", 'j', 'r', 'y');
	// printf("c is : %12c\nand %0c\nand %-23c yeah\n", 'j', 'r', 'y');
	ft_printf("mine\n %0-14c oy\n %06c eheh\n", '1', 'j');
	printf("printf\n %0-14c oy\n %06c eheh\n", '1', 'j');
	return (0);
}