#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Move(char p1, char p2)
{
	printf(" %c->%c ", p1, p2);
}

void Hanoi(int n, char pos1, char pos2, char pos3)
{
	if (n == 1)
	{
		Move(pos1, pos3);
	}
	else
	{
		Hanoi(n - 1, pos1, pos3, pos2);
		Move(pos1, pos3);
		Hanoi(n - 1, pos2, pos1, pos3);
	}
}

int main()
{
	Hanoi(1, 'A', 'B', 'C');
	printf("\n");
	Hanoi(2, 'A', 'B', 'C');
	printf("\n");
	Hanoi(3, 'A', 'B', 'C');
	return 0;
}