#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n >= 3)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	int ret = Fib(num);
	printf("%d\n", ret);
	return 0;
}