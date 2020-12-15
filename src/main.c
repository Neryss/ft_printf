#include "../includes/ft_printf.h"

int main(void)
{
	printf("test\n");
	ft_printf("c is : %c\n%d\n%s\n", 'j', 123, "salut");
	return (0);
}