//Problem:
//(1)
//We have an array here: arr = { 1,1,1,3,4,5,4,3,5 }
//And you have to use algorithms to find the odd number here
//requirements: Complexity of Time: O(N)
//(2)
//Change the array to arr = { 2,2,2,3,3,3,6,4,5,5,4,6 }
//Use the algorithms to find the two odd numbers here
//same requirements as the first one

#include <stdio.h>
int main()
{



	int arr[9] = { 1,1,1,3,4,5,4,3,5 };
	int eor = 0;
	for (int i = 0; i < 9; i++)
		eor = eor ^ arr[i];
	printf("The answer to the first question is %d\n", eor);





	int arr1[12] = { 2,2,2,4,4,4,6,4,5,5,4,6 };
	int eor1 = 0;
	int eor2 = 0;
	int count = 0;
	for (int i = 0; i < 12; i++)
		eor1 = eor1 ^ arr1[i];//a ^ b
	int rightOne = eor1 & (~eor1 + 1);
	for (int i = 0; i < 12; i++)
	{
		if ((arr1[i] & rightOne) == rightOne)
			eor2 = eor2 ^ arr1[i];
	}
	int answer3 = eor2 ^ eor1;
	printf("the two number is %d, %d", eor2, answer3);
	return 0;
}


//2,4,5,6
//eor1: 00000110
//rightone: 00000010
//2: 00000010  00000010
//4: 00000100  00000000

//Time Complexity: O(N)
//Space Complexity: O(1)