#define _CRT_SECURE_NO_WARNINGS 1

#include"Test_1.h"

void menu()
{
	printf("************************************\n");
	printf("*** 1.Creat f(x)    2.Creat g(x) ***\n");
	printf("*** 3.Print         0.Exit       ***\n");
	printf("************************************\n");
}

enum Option
{
	Exit,
	CreatF,
	CreatG,
	Print
};

int main()
{
	SL listF;
	SL listG;
	InitSeqList(&listF);
	InitSeqList(&listG);
	int input = 0;
	do
	{
		menu();
		printf("Please select program>>");
		scanf("%d", &input);
		switch (input)
		{
		case CreatF:
			SeqListF(&listF);
			break;
		case CreatG:
			SeqListG(&listG);
			break;
		case Print:
			SeqListPrint(&listF, &listG);
			break;
		case Exit:
			SeqListDestroy(&listF, &listG);
			printf("\n<Exit the program>\n\n");
			break;
		default:
			printf("\n<Wrong selection, please select again>\n\n");
			break;
		}

	} while (input);
	return 0;
}