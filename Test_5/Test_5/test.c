#define _CRT_SECURE_NO_WARNINGS 1

#include"Test_5.h"

int main()
{
	char arr[50] = { 0 };
	gets(arr);
	printf("------------------------------\n");
	printf("PrevOrder>>");
	str_PrevOrder(arr, 0);
	printf("\n\n");

	printf("InOrder>>");
	str_InOrder(arr, 0);
	printf("\n\n");

	printf("PostOrder>>");
	str_PostOrder(arr, 0);
	printf("\n\n");

	printf("Result>>");
	int ret = str_Calculate(arr);
	printf("%d\n", ret);
	return 0;
}