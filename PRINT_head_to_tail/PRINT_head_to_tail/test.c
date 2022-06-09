#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d ", n % 10);
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	Print(num);
	return 0;
}