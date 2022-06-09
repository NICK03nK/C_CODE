#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>

int Is_Prime(int i)
{
	int j = 0;
	for (j = 2; j <= sqrt(i); j++)     //优化:  j<=sqrt(i)  可以算的更少
	{
		if (i % j == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (Is_Prime(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}