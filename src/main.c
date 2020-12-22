#include "../includes/ft_printf.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	int r, d = 0;
<<<<<<< HEAD
	r = ft_printf(" %0.s %0.s ", "123", "4567");
	ft_printf("\n");
	d = printf(" %0.s %0.s ", "123", "4567");
	printf("\n\nreturn mine is [%d]", r);
	printf("\n\nreturn libc is [%d]", d);
=======
		r = ft_printf("[ *%*.*x* *%*.*x* ]", 10, 21, -101, 10, 21, 34);
	ft_printf("\n");	
	// ft_printf("%10.21x|", 134);
	d = printf("[ *%*.*x* *%*.*x* ]", 10, 21, -101, 10, 21, 34);
	// printf("%10.21x|", -101);
	// printf("%10.21x|", 134);
	printf("\n");
	// printf("%10.21x", 134);

	// printf("\n\nreturn mine is [%d]", r);
	// printf("\n\nreturn libc is [%d]", d);
>>>>>>> test
	return (0);
}
