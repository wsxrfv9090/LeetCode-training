//selection sort

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//generating random number
void generate_rand100(int arr[], int sz)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < sz; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
}

//swap two numbers
void swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}


//selection sort: select continuously and determine weather or the one of which two 
//numbers are smaller.
//And put the smaller one in the front of the two numbers and do it for every other
//numbers from i = 0 to all the way to i = sz.
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

//The logics of this main function: 
//Initiating the array
//Culculate the size of the array and store it as a variable
//Call the generating function to filled the mensioned array with random numbers
//Use selection sort to sort out the array
//At last use a for loop to print out all the numbers.
int main()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	generate_rand100(arr, sz);
	selection_sort(arr, sz);
	for (int i = 0; i < 100; i++)
		printf("%d\n", arr[i]);
	return 0;
}

//Time Complexity: O(N)
//Space Complexity: O(1)