//selection sort

#include <stdlib.h>
#include <time.h>
#include <stdio.h>


void generate_rand100(int arr[], int sz)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < sz; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
}

void swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}


void selection_sort(int arr[], int sz)
{
	if (arr == NULL || sz < 2)
		return;
	for (int i = 0; i < sz; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			(arr[i] < arr[j]) ? arr[i] == arr[i] : swap(&arr[i], &arr[j]);
		}
	}
}

int main()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	generate_rand100(arr, sz);
	selection_sort(arr, sz);
	for (int i = 0; i < 100; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}