#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//µü´ú
//int Fac(int n)
//{
//	int ret = 1;
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}

//µÝ¹é
int Fac(int n)
{
	if (n > 1)
	{
		return Fac(n - 1) * n;
	}
	return 1;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	int n = Fac(num);
	printf("%d\n", n);
	return 0;
}