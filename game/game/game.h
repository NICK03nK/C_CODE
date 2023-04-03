#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//符号的定义
#define ROW 3
#define COL 3

//函数的声明

//初始化棋盘
void Initboard(char board[ROW][COL], int row, int col);
//打印棋盘
void Displayboard(char board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);
//判断游戏状态
char IsWin(char board[ROW][COL], int row, int col);
//               (IsWin函数
//	                 玩家赢---'*'
//	                 电脑赢---'#'
//                   平局---'Q'
//	                 游戏结束---'C')