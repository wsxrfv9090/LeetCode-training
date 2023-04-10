//Explanation and Extension of Binary Search Algorithm
//
//1) Binary search algorithm can be used to find whether a certain number exists in a sorted array.
// 
//2) Binary search algorithm can be used to find the leftmost position of a number greater than or equal to a given number in a sorted array.
// 
//3) Binary search algorithm can also be used to solve the problem of finding a local minimum in an array. adjacent numbers are different.


#include <stdio.h>
#include "header.h"
#include <time.h>
#include <stdlib.h>

#define TEST_ARRAY_SIZE 100
#define TARGET 15



int menu()
{
	do
	{
		printf("three answer test:\n");
		printf("1) Binary search algorithm can be used to find whether a certain number exists in a sorted array.\n");
		printf("2) Binary search algorithm can be used to find the leftmost position of a number greater than or equal to a given number in a sorted array.\n");
		printf("3) Binary search algorithm can also be used to solve the problem of finding a local minimum in an array.\n");
		int option = 0;
		scanf_s("%d", &option);
		if (option != 1 && option != 2 && option != 3)
			printf("input error, please try again\n");
		else
			return option;
	} while (1);
}
int binary_sorted_exist(int arr[], int sz,int target)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int delimiter = (left + right) / 2;
		if (arr[delimiter] == target)
			return 0;
		else if (arr[delimiter] > target)
			right = delimiter - 1;
		else
			left = delimiter + 1;
	}
	return 1;

}
int binary_sorted_leftmost(int arr[], int sz, int target)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int delimiter = (left + right) / 2;
		if (arr[delimiter] >= target)
			right = delimiter;
		else if (arr[delimiter]<target)
			left = delimiter+1;
		if (left == right && arr[left] == target)
			return left;
		else if (left == right && arr[left] != target)
			return -1;
	}
}
void adjacent_num_unequal(int arr[], int sz)
{
	for (int i = 0; i < TEST_ARRAY_SIZE; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			srand((unsigned int)time(NULL));
			int rand_index;
			do
			{
				rand_index = rand() % TEST_ARRAY_SIZE;
				if (arr[rand_index] == arr[i+1] || arr[rand_index] == arr[i - 1])
					continue;
				if (arr[i] == arr[rand_index - 1] || arr[i] == arr[rand_index + 1])
					continue;
				swap(&arr[rand_index], &arr[i]);
				break;
			} while (1);
		}
	}
}
int binary_notsorted_local_minimum(int arr[], int sz)
{
	if (arr[0] < arr[1])
		return 0;
	if (arr[sz - 1] < arr[sz - 2])
		return sz - 1;
	int left_index = 1;
	int right_index = sz - 2;
	for (;;)
	{
		int middle_index = (left_index + right_index) / 2;
		if (arr[middle_index] < arr[middle_index + 1] && arr[middle_index] < arr[middle_index - 1])
			return middle_index;
		if (arr[middle_index] > arr[middle_index + 1] && arr[middle_index] > arr[middle_index - 1])
		{
			srand((unsigned int)time(NULL));
			int tmp = rand() % 2 + 1;
			if (tmp == 1)
				left_index = middle_index;
			else if(tmp==2)
				right_index = middle_index;
		}
		if (arr[middle_index] > arr[middle_index + 1] && arr[middle_index] < arr[middle_index - 1])
			left_index = middle_index;
		if (arr[middle_index] > arr[middle_index - 1] && arr[middle_index] < arr[middle_index + 1])
			right_index = middle_index;
		if (right_index == left_index + 2)
			return (left_index + right_index) / 2;
	}
	
	if (arr[1] < arr[0])
		left_index = 1;
	if (arr[sz - 2] < arr[sz - 1])
		right_index = sz - 2;
	//if (arr[middle_index]>arr[middle_index+1])
	return 1;
}

int main()
{
	int option = menu();
	int arr[TEST_ARRAY_SIZE] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	switch (option)
	{
	case 1:
		generate_rand(arr, sz);
		insertion_sort(arr, sz);
		int target1 = TARGET;
		int result1 = binary_sorted_exist(arr, sz, target1);
		if (result1 == 0)
			printf("exist\n");
		else if (result1 == 1)
			printf("doesn't exist\n");
		else
			printf("error outputing\n");
		for (int i = 0; i < sz; i++) //check
			printf("%d\n", arr[i]);
		break;
	case 2:
		generate_rand(arr, sz);
		insertion_sort(arr, sz);
		int target2 = TARGET;
		int result2 = binary_sorted_leftmost(arr, sz, target2);
		if (result2 > -1 && result2 < sz)
			printf("the sub-number of it is %d\n", result2);
		else if (result2 = -1)
			printf("target does not exist\n");
		else
			printf("output error\n");
		for (int i = 0; i < sz; i++) //check
		{
			if (arr[i] == TARGET)
			{
				printf("%d\n", i);
			}
		}
		break;
	case 3:
		generate_rand(arr, sz);
		adjacent_num_unequal(arr, sz);
		//for (int i = 0; i < sz; i++) //check
		//{
		//	if (arr[i] == arr[i + 1])
		//		printf("error detected in the adjacent_num_unequal function");
		//}
		int result3 = binary_notsorted_local_minimum(arr, sz);
		if (result3 > -1 && result3 < sz)
			printf("the sub-number of it is %d\n", result3);
		else
			printf("output error\n");
		//for (int i = 0; i < sz; i++) //check
		//	printf("%d\n", arr[i]);
		break;
	}
	return 0;
}