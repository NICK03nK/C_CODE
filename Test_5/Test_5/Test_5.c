#define _CRT_SECURE_NO_WARNINGS 1

#include"Test_5.h"

void str_PrevOrder(char* a, int parent)
{
	if (a[parent] == '\0')
	{
		return;
	}
	printf("%c ", a[parent]);
	str_PrevOrder(a, parent * 2 + 1);
	str_PrevOrder(a, parent * 2 + 2);
}

void str_InOrder(char* a, int parent)
{
	if (a[parent] == '\0')
	{
		return;
	}
	str_InOrder(a, parent * 2 + 1);
	printf("%c ", a[parent]);
	str_InOrder(a, parent * 2 + 2);
}

void str_PostOrder(char* a, int parent)
{
	if (a[parent] == '\0')
	{
		return;
	}
	str_PostOrder(a, parent * 2 + 1);
	str_PostOrder(a, parent * 2 + 2);
	printf("%c ", a[parent]);
}

int str_Calculate(char* a)
{

}