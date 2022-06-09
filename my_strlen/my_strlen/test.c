#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//µü´ú
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//µİ¹é
int my_strlen(char* str)
{
	if (*str != '\0')
	{
		return 1 + my_strlen(str + 1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	char arr[] = "focus on your target!";
	int ret = my_strlen(arr);
	printf("%d\n", ret);
	return 0;
}