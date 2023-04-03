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
		printf("��ѡ�����>>");
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
			SaveContactData(&con);
			DestroyContact(&con);
			printf("\n<�˳�����>\n\n");
			break;
		default:
			printf("\n<ѡ�����������ѡ��>\n\n");
			break;
		}
	} while (input);
	return 0;
}