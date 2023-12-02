//Merge Sort
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define TEST_ARRAY_SIZE 10

void merge(int arr[], int L, int M, int R)
{
	int space2[TEST_ARRAY_SIZE] = { 0 };
	int i = 0;
	int p1 = L;
	int p2 = M + 1;
	while (p1 <= M && p2 <= R)
		space2[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
	while (p1 <= M)
		space2[i++] = arr[p1++];
	while (p2 <= R)
		space2[i++] = arr[p2++];
	for (i = 0; i < TEST_ARRAY_SIZE; i++)
		arr[L + i] = space2[i];
}

void generate_rand(int arr[], int sz)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < sz; i++)
	{
		arr[i] = rand() % TEST_ARRAY_SIZE + 1;
	}
}

void process(int arr[], int L, int R)
{
	if (L == R)
		return;
	int mid = L + ((R - L) >> 1);
	process(arr, L, mid);
	process(arr, mid+1, R);
	merge(arr, L, mid, R);
}

void merge_sort(int arr[], int sz)
{
	if (arr == NULL || sz < 2)
		return;
	process(arr, 0, sz - 1);
}

int main()
{
	int arr[TEST_ARRAY_SIZE] = { 0 };
	int sz = TEST_ARRAY_SIZE;
	generate_rand(arr, sz);
	merge_sort(arr, sz);
	for (int i = 0; i < TEST_ARRAY_SIZE; i++)
		printf("%d\n", arr[i]);
	return 0;
}