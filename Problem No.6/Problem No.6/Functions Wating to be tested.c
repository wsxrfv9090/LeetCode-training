#include <time.h>

void swap(int* a, int* b)
{
	*a ^= *b ^= *a ^= *b;
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

