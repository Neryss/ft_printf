#include "../includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("test\n");
	ft_printf("c is : %12c\nand %2c\nand %23c\n", 'j', 'r', 'y');
	printf("c is : %12c\nand %02c\nand %023c\n", 'j', 'r', 'y');
	return (0);
}