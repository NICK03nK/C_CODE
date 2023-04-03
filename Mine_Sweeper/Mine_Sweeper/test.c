#define _CRT_SECURE_NO_WARNINGS 1

#include"Mine_Sweeper.h"

void menu()
{
	printf("******************************\n");
	printf("*********   1.PLAY   *********\n");
	printf("*********   0.EXIT   *********\n");
	printf("******************************\n");
}

void Game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	SetMine(mine, ROW, COL);
	/*DisplayBoard(mine, ROW, COL);*/
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	CheckMine(mine, show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ�����>>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("\n<�˳���Ϸ>\n\n");
			break;
		default:
			printf("\n<ѡ�����������ѡ��>\n\n");
			break;
		}
	} while (input);
	return 0;
}