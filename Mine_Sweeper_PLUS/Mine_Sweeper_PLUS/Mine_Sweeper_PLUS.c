#define _CRT_SECURE_NO_WARNINGS 1

#include"Mine_Sweeper_PLUS.h"

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

void menu()
{
	printf("********************************\n");
	printf("*********   1.CHECK    *********\n");
	printf("*********   2.MARK     *********\n");
	printf("*********   3.UNMARK   *********\n");
	printf("********************************\n");

}

void Unfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win)
{
	if (x<1 || x>ROW || y<1 || y>COL)
	{
		return;
	}
	if (show[x][y] != '*')
	{
		return;
	}
	int count = get_mine_count(mine, x, y);
	if (count > 0)
	{
		(*win)++;
		show[x][y] = count + '0';
		return;
	}
	else if (count == 0)
	{
		(*win)++;
		show[x][y] = ' ';
		Unfold(mine, show, x - 1, y, win);
		Unfold(mine, show, x - 1, y + 1, win);
		Unfold(mine, show, x, y + 1, win);
		Unfold(mine, show, x + 1, y + 1, win);
		Unfold(mine, show, x + 1, y, win);
		Unfold(mine, show, x + 1, y - 1, win);
		Unfold(mine, show, x, y - 1, win);
		Unfold(mine, show, x - 1, y - 1, win);
	}
}

int Check(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int* win)
{
	int x = 0;
	int y = 0;
again:
	printf("\n������Ҫ�Ų������>>");
	scanf("%d %d", &x, &y);
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		if (show[x][y] == '*' || show[x][y] == '!')
		{
			if (mine[x][y] == '1')
			{
				system("cls");
				printf("\n<���ź�����ȵ����ˣ���Ϸ����>\n");
				DisplayBoard(mine, ROW, COL);
				return 1;
			}
			else
			{
				Unfold(mine, show, x, y, win);
				DisplayBoard(show, row, col);
			}
		}
		else
		{
			printf("\n<���������Ų飬�����ظ��Ų飬����������>\n");
			goto again;
		}
	}
	else
	{
		printf("\n<����Ƿ�������������>\n");
		goto again;
	}
	return 0;
}

void Mark(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("\n������Ҫ��ǵ�����>>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x][y] == '!')
			{
				printf("\n<�������ѱ�ǣ������ظ���ǣ�����������>\n");
			}
			else
			{
				board[x][y] = '!';
				DisplayBoard(board, row, col);
				break;
			}
		}
		else
		{
			printf("\n<����Ƿ�������������>\n\n");
		}
	}
}

void UnMark(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("\n������Ҫȡ����ǵ�����>>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x][y] != '!')
			{
				int i = 0;
				int j = 0;
				int flag = 1;
				for (i = 1; i <= row; i++)
				{
					for (j = 1; j <= col; j++)
					{
						if (board[i][j] == '!')
						{
							flag = 0;
							goto out;
						}
					}
				}
			out:
				if (flag)
				{
					printf("\n<������δ����ǣ�����ȡ��>\n\n");
					return;
				}
				else
				{
					printf("\n<������δ��ǣ�����ȡ��������������>\n");
				}
			}
			else
			{
				board[x][y] = '*';
				DisplayBoard(board, row, col);
				break;
			}
		}
		else
		{
			printf("\n<����Ƿ�������������>\n\n");
		}
	}
}

void CheckMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int ret = 0;
	int win = 0;
	int input = 0;
	do
	{
		menu();
		printf("\n��ѡ�����>>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			if (win < row * col - MINE)
			{
				ret = Check(mine, show, row, col, &win);
				if (ret == 1)
				{
					return;
				}
			}
			if (win == row * col - MINE)
			{
				system("cls");
				printf("<��ϲ�㣬���׳ɹ�>\n");
				DisplayBoard(mine, row, col);
				return;
			}
			break;
		case 2:
			Mark(show, row, col);
			break;
		case 3:
			UnMark(show, row, col);
			break;
		default:
			printf("\n<ѡ�����������ѡ��>\n\n");
			break;
		}
		system("cls");
		DisplayBoard(show, row, col);
	} while (input);
}