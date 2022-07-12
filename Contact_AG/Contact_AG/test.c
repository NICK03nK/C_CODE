#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void menu()
{
	printf("**************************************\n");
	printf("****     1.Add        2.Del       ****\n");
	printf("****     3.Search     4.Modify    ****\n");
	printf("****     5.Sort       6.Show      ****\n");
	printf("****            0.Exit            ****\n");
	printf("**************************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择程序>>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			break;
		case DEL:
			break;
		case SEARCH:
			break;
		case MODIFY:
			break;
		case SORT:
			break;
		case SHOW:
			break;
		case EXIT:
			printf("\n<退出程序>\n\n");
			break;
		default:
			printf("\n<选择错误，请重新选择>\n\n");
			break;
		}
	} while (input);
	return 0;
}