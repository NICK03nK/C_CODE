#define _CRT_SECURE_NO_WARNINGS 1

#include"Mine_Sweeper.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = MINE;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("\n----MineSweeper----\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----MineSweeper----\n\n");
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y] + board[x - 1][y + 1] + board[x][y + 1] + board[x + 1][y + 1] + board[x + 1][y] + board[x + 1][y - 1] + board[x][y - 1] + board[x - 1][y - 1] - 8 * '0';
}

void CheckMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - MINE)
	{
		printf("请输入要排查的坐标>>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("\n<该坐标已排查，无需重复排查，请重新输入坐标>\n\n");
			}
			else
			{
				if (mine[x][y] == '1')
				{
					printf("\n<很遗憾，你踩到雷了，游戏结束>\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					show[x][y] = get_mine_count(mine, x, y) + '0';
					DisplayBoard(show, ROW, COL);
					win++;
				}
			}
		}
		else
		{
			printf("\n<坐标非法，请重新输入>\n\n");
		}
	}
	if (win == row * col - MINE)
	{
		printf("<恭喜你，排雷成功>\n");
		DisplayBoard(mine, ROW, COL);
	}
}