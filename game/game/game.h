#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//���ŵĶ���
#define ROW 3
#define COL 3

//����������

//��ʼ������
void Initboard(char board[ROW][COL], int row, int col);
//��ӡ����
void Displayboard(char board[ROW][COL], int row, int col);
//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMove(char board[ROW][COL], int row, int col);
//�ж���Ϸ״̬
char IsWin(char board[ROW][COL], int row, int col);
//               (IsWin����
//	                 ���Ӯ---'*'
//	                 ����Ӯ---'#'
//                   ƽ��---'Q'
//	                 ��Ϸ����---'C')