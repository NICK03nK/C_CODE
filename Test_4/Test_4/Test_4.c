#define _CRT_SECURE_NO_WARNINGS 1

#include"Test_4.h"

void Partion()
{
	static int i = 1;
	printf("Partion %d>>", i++);
}

void Split(char* a)
{
	int begin = 0;
	int end = 0;
	int i = 0;
	printf("Partion result>>\n");
	for (i = 0; a[begin] != '\0'; i++)
	{
		if (a[i] == ' ' || a[i] == '\0')
		{
			Partion();
			end = i - 1;
			int j = 0;
			for (j = begin; j <= end; j++)
			{
				printf("%c", a[j]);
			}
			begin = i + 1;
			printf("\n");
		}
	}
}