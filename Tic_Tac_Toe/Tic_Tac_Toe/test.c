#define _CRT_SECURE_NO_WARNINGS 1

#include"Tic_Tac_Toe.h"

void menu()
{
	printf("******************************\n");
	printf("********    1.PLAY    ********\n");
	printf("********    0.EXIT    ********\n");
	printf("******************************\n");
}

void Game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = WinCheck(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = WinCheck(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("\n<��һ�ʤ>\n\n");
	}
	if (ret == '#')
	{
		printf("\n<���Ի�ʤ>\n\n");
	}
	if (ret == 'Q')
	{
		printf("\n<ƽ��>\n\n");
	}
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