//Group members:
//Yuanxiang Wang
//Erqian Gao
//Qifan Yang

#include <iostream>

using namespace std;

int* mergeSort(int*, int);
int* merge(int*, int*, int, int);

int main()
{
	int n;
	cin >> n;
	int* numbers = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	int* result = mergeSort(numbers, n);

	for (int i = 0; i < n; i++)
	{
		cout << result[i] <<" ";
	}
}

int* mergeSort(int* a1, int a1Size)
{
	if (a1Size == 1)
	{
		return a1;
	}
	int frontSize = a1Size / 2;
	int backSize = a1Size - frontSize;

	int* front = new int[frontSize];
	int* back = new int[backSize];

	for (int i = 0; i < a1Size; i++)
	{
		if (i < frontSize)
		{
			front[i] = a1[i];
		}
		else
		{
			back[i - frontSize] = a1[i];
		}
	}

	return merge(mergeSort(front, frontSize), mergeSort(back, backSize), frontSize, backSize);
}


int* merge(int* a1, int* a2, int a1Size, int a2Size)
{
	if (a1Size == 0)
	{
		return a2;
	}
	if (a2Size == 0)
	{
		return a1;
	}

	int* finalArray = new int[a1Size + a2Size];

	if (a1[0] <= a2[0])
	{
		finalArray[0] = a1[0];
		int* newA1 = new int[a1Size - 1];
		for (int i = 0; i < a1Size - 1; i++)
		{
			newA1[i] = a1[i + 1];
		}

		int* result = merge(newA1, a2, a1Size - 1, a2Size);
		for (int i = 0; i < a1Size + a2Size - 1; i++)
		{
			finalArray[i + 1] = result[i];
		}
		
		delete[] result;

		return finalArray;
	}
	else
	{
		finalArray[0] = a2[0];
		int* newA2 = new int[a2Size - 1];
		for (int i = 0; i < a2Size - 1; i++)
		{
			newA2[i] = a2[i + 1];
		}

		int* result = merge(a1, newA2, a1Size, a2Size-1);
		for (int i = 0; i < a1Size + a2Size - 1; i++)
		{
			finalArray[i + 1] = result[i];
		}

		delete[] result;

		return finalArray;
	}
	return finalArray;
}