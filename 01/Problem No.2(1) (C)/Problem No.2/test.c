#include <stdio.h>

void swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int main()
{
	int a = 10;
	int b = 5;
	swap(&a, &b);
	printf("a = %d", a);
	printf("b = %d", b);
	return 0;
}