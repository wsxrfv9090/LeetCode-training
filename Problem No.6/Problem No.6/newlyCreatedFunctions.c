#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int errorcount = 0;

void generate_array(int arr[], int sz, int start)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < sz; i++)
		arr[i] = rand() % sz + start;
}

void copy_array(int arr1[], int arr2[], int sz)
{
	for (int i = 0; i < sz; i++)
		arr2[i] = arr1[i];
}

void error(int i, int a, int b)
{
	errorcount += 1;
	printf("ERROR ACCURRED:\n");
	printf("index is: %d\n", i);
	printf("arr1 number is: %d\n", a);
	printf("arr2 number is: %d\n", b);
}

void check(int arr1[], int arr2[], int sz)
{
	for (int i = 0; i < sz; i++)
		arr1[i] == arr2[i] ? arr1[i] == arr1[i] : error(i, arr1[i], arr2[i]);
	printf("Total error count: %d\n", errorcount);
}


