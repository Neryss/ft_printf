#include "../includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("test\n");
	// ft_printf("c is : %12c\nand %0c\nand %-23c yeah\n", 'j', 'r', 'y');
	// printf("c is : %12c\nand %0c\nand %-23c yeah\n", 'j', 'r', 'y');
	ft_printf("%-012c\n", '1');
	printf("%-012c\n", '1');
	return (0);
}