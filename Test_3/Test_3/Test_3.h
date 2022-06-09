#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define InitCap 7

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
	int capacity;
}Queue;

void QueueInit(Queue* pq);

void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq);

void QueuePop(Queue* pq);

QDataType QueueFront(const Queue* pq);

void QueuePrint(const Queue* pq);