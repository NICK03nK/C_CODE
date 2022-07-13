#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void MENU()
{
	printf("**************************************\n");
	printf("****     1.Add        2.Delete    ****\n");
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
	Contact con;
	InitContact(&con);
	int input = 0;
	do
	{
		MENU();
		printf("请选择程序>>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DeleteContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EXIT:
			DestroyContact(&con);
			printf("\n<退出程序>\n\n");
			break;
		default:
			printf("\n<选择错误，请重新选择>\n\n");
			break;
		}
	} while (input);
	return 0;
}