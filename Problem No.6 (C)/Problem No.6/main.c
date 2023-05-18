//Explanation:
//Going to write a logarithmic device to check if the codes I wrote correct.
//Involves two algorithms from Problem No.3 (Bubble Sort) Problem No.4 (Insertion Sort)
//From small to big

#include "sortAlgorithms.h"
#include "newFunction.h"

#define TEST_TIMES 500000
#define ARRAY_SIZE 100
#define ARRAY_RANGE_START 1

int main()
{
	int arr1[ARRAY_SIZE] = { 0 };
	int arr2[ARRAY_SIZE] = { 0 };
	generate_array(arr1, ARRAY_SIZE, ARRAY_RANGE_START);
	copy_array(arr1, arr2,ARRAY_SIZE);
	for (int i = 0; i < TEST_TIMES; i++)
	{
		bubble_sort(arr1, ARRAY_SIZE);
		insertion_sort(arr2, ARRAY_SIZE);
		check(arr1, arr2, ARRAY_SIZE);
	}
	return 0;
}