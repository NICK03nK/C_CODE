#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void ArrPrint(const int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void BubbleSort(int* a, int n)
{
	int end = n;
	int i = 0;
	while (end >= 2)
	{
		for (i = 1; i < end; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}
		end--;
	}
}

int main()
{
	int arr[] = { 7,4,3,2,1,5,7,88,9,76,5 };
	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	ArrPrint(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}