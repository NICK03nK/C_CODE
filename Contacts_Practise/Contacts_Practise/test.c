#define _CRT_SECURE_NO_WARNINGS 1

#include"contacts_practise.h"

void menu()
{
	printf("******************************\n");
	printf("****  1.ADD      2.DEL    ****\n");
	printf("****  3.SERCH    4.MODIF  ****\n");
	printf("****  5.SORT     6.PRINT  ****\n");
	printf("****        0.EXIT        ****\n");
	printf("*****************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SERCH,
	MODIF,
	SORT,
	PRINT
};

int main()
{
	int input = 0;
	Contacts con;
	InitContacts(&con);
	do
	{
		menu();
		printf("��ѡ�����>>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContacts(&con);
			break;
		case DEL:
			DelContacts(&con);
			break;
		case SERCH:
			SerchContacts(&con);
			break;
		case MODIF:
			ModifContacts(&con);
			break;
		case SORT:
			break;
		case PRINT:
			PrintContacts(&con);
			break;
		case EXIT:
			printf("\n<�˳�ͨѶ¼>\n\n");
			break;
		default:
			printf("\n<ѡ�����������ѡ��>\n\n");
			break;
		}
	} while (input);
	return 0;
}