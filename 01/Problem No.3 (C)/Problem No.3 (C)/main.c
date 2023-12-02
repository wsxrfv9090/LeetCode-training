//insertion sort

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define TEST_ARRAY_SIZE 100


void generate_rand(int arr[], int sz)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < sz; i++)
	{
		arr[i] = rand() % TEST_ARRAY_SIZE + 1;
	}
}

void swap(int* a, int* b)
{
	*a ^= *b ^= *a ^= *b;
}


void insertion_sort(int arr[], int sz)
{
	if (arr == NULL || sz < 2)
		return;
	for (int i = 1; i < sz; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			arr[j] < arr[j + 1] ? arr[j] == arr[j] : swap(&arr[j], &arr[j + 1]);
		}
	}
}

int main()
{
	int arr[TEST_ARRAY_SIZE] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	generate_rand(arr, sz);
	insertion_sort(arr, sz);
	for (int i = 0; i < TEST_ARRAY_SIZE; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}