#define _CRT_SECURE_NO_WARNINGS 1

#include"Test_3.h"

QNode* BuyNewode(QDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
	pq->capacity = InitCap;
	pq->head = pq->tail = BuyNewode(0);
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		pq->tail->next = BuyNewode(0);
		pq->tail = pq->tail->next;
	}
	pq->tail->next = pq->head;
	pq->tail = pq->tail->next;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	QNode* next = cur->next;
	while (pq->capacity)
	{
		if (pq->capacity <= 2)
		{
			free(cur);
			cur = next;
		}
		else
		{
			free(cur);
			cur = next;
			next = next->next;
		}
		pq->capacity--;
	}
	pq->head = pq->tail = cur = next = NULL;
}

void QueuePrint(const Queue* pq)
{
	printf("\n");
	while (pq->size)
	{
		printf("%d ", QueueFront(pq));
		QueuePop(pq);
	}
	printf("\n\n");
}

void QueuePush(Queue* pq)
{
	assert(pq);
	if (pq->size == pq->capacity)
	{
		printf("队列已满，无法入队\n");
		return;
	}
	else
	{
		QDataType x = 0;
		printf("请输入数据>>");
		scanf("%d", &x);
		pq->tail->data = x;
		pq->tail = pq->tail->next;
		pq->size++;
	}
	printf("\n");
}

void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->size == 0)
	{
		printf("队列为空\n");
		return;
	}
	else
	{
		pq->head->data = 0;
		pq->head = pq->head->next;
		pq->size--;
	}
}

QDataType QueueFront(const Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}