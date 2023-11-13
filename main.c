#include "main.h"

int main(void)
{
	int len;

	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d %d %s]\n", 456, len, "He is awesome");

	return 0;
}