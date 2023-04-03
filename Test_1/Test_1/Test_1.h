#pragma once

#include<stdio.h>
#include<stdlib.h>

#define InitCap 4

typedef int DataType;

typedef struct SeqList
{
	DataType* a;
	int sz;
	int capacity;
}SL;

void InitSeqList(SL* plistF);

void SeqListF(SL* plistF);

void SeqListG(SL* plistG);

void SeqListPrint(const SL* plistF, const SL* plistG);

void SeqListDestroy(SL* plistF, SL* plistG);