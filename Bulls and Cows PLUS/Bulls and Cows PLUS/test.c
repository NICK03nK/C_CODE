#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("***************************\n");
	printf("********   1.PLAY   *******\n");
	printf("********   0.EXIT   *******\n");
	printf("***************************\n");
}

void Game()
{
	printf("\n<游戏开始>\n\n");
	printf("\n<请在1到100内猜一个数>\n\n");
	printf("\n<你的电脑将在60秒后关机，若猜出数字，则取消关机>\n\n");
	system("shutdown -s -t 120");
	int key = rand() % 100 + 1;
	int num = 0;
	while (1)
	{
		printf("请输入数字>>");
		scanf("%d", &num);
		if (num < key)
		{
			printf("\n<数小了，请往大猜>\n\n");
		}
		else if (num > key)
		{
			printf("\n<数大了，请往小猜>\n\n");
		}
		else
		{
			printf("\n<恭喜你，猜对了>\n\n");
			printf("\n<取消关机成功>\n\n");
			system("shutdown -a");
			break;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择>>");
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
		}
	} while (input);
	return 0;
}