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
	printf("\n<��Ϸ��ʼ>\n\n");
	printf("\n<����1��100�ڲ�һ����>\n\n");
	printf("\n<��ĵ��Խ���60���ػ������³����֣���ȡ���ػ�>\n\n");
	system("shutdown -s -t 120");
	int key = rand() % 100 + 1;
	int num = 0;
	while (1)
	{
		printf("����������>>");
		scanf("%d", &num);
		if (num < key)
		{
			printf("\n<��С�ˣ��������>\n\n");
		}
		else if (num > key)
		{
			printf("\n<�����ˣ�����С��>\n\n");
		}
		else
		{
			printf("\n<��ϲ�㣬�¶���>\n\n");
			printf("\n<ȡ���ػ��ɹ�>\n\n");
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
		printf("��ѡ��>>");
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
		}
	} while (input);
	return 0;
}