//bubble sort

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


void bubble_sort(int arr[], int sz)
{
	if (arr == NULL || sz < 2)
		return;
	for (int i = sz; i >= 0; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			arr[j] > arr[j + 1] ? swap(&arr[j], &arr[j + 1]) : arr[j] == arr[j];
		}
	}
}

int main()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	generate_rand100(arr, sz);
	bubble_sort(arr, sz);
	for (int i = 0; i < 100; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}