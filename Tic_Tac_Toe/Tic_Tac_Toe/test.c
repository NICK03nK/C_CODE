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
		printf("\n<玩家获胜>\n\n");
	}
	if (ret == '#')
	{
		printf("\n<电脑获胜>\n\n");
	}
	if (ret == 'Q')
	{
		printf("\n<平局>\n\n");
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择程序>>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("\n<退出游戏>\n\n");
			break;
		default:
			printf("\n<选择错误，请重新选择>\n\n");
			break;
		}
	} while (input);
	return 0;
}