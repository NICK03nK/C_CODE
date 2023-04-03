#define _CRT_SECURE_NO_WARNINGS 1

#include"Test_3.h"

void menu()
{
	printf("***************************************\n");
	printf("****  1.QueuePush      2.QueuePop  ****\n");
	printf("****  3.QueuePrint     0.Exit      ****\n");
	printf("***************************************\n");
}

enum Option
{
	Exit,
	Push,
	Pop,
	Print
};

int main()
{
	Queue q;
	QueueInit(&q);
	int input = 0;
	QDataType x = 0;
	do
	{
		menu();
		printf("请选择程序>>");
		scanf("%d", &input);
		switch (input)
		{
		case Push:
			QueuePush(&q);
			break;
		case Pop:
			printf("\n");
			printf("%d", QueueFront(&q));
			QueuePop(&q);
			printf("\n\n");
			break;
		case Print:
			QueuePrint(&q);
			break;
		case Exit:
			QueueDestroy(&q);
			break;
		default:
			printf("\n<选择错误，请重新输入>\n\n");
			break;
		}
	} while (input);
	return 0;
}