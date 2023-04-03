#define _CRT_SECURE_NO_WARNINGS 1

#include"Test_4.h"

int main()
{
	char arr[Length] = { 0 };
	printf("Please input string(length<=50)>>");
	gets(arr);
	Split(arr);
	return 0;
}