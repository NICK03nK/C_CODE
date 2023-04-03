#define _CRT_SECURE_NO_WARNINGS 1

#include"Test_1.h"

void InitSeqList(SL* plist)
{
	plist->a = (DataType*)calloc(InitCap, sizeof(DataType));
	plist->sz = 0;
	plist->capacity = InitCap;
}

void SeqListCheakCap(SL* plist, int num)
{
	DataType* tmp = (DataType*)realloc(plist->a, plist->capacity * 2 * sizeof(DataType));
	if (tmp)
	{
		plist->a = tmp;
		plist->sz = num;
		plist->capacity *= 2;
	}
	else
	{
		printf("\n<realloc failed>\n\n");
	}
}

void SeqListTypeIn_F(SL* plistF, int num)
{
	printf("\n<Please enter the coefficient of x and fill out the missing term with zero>\n\n");
	int i = 0;
	DataType x = 0;
	for (i = 0; i <= num; i++)
	{
		printf("Please enter the coefficient of x^%d>>", i);
		scanf("%d", &x);
		plistF->a[i] = x;
	}
	printf("\n");
	printf("f(x) = ");
	for (i = 0; i <= num; i++)
	{
		if (plistF->a[i])
		{
			printf("(%dx^%d)", plistF->a[i], i);
			int j = 0;
			if (i < num)
			{
				printf(" + ");
			}
		}
	}
	printf("\n\n");
}

void SeqListTypeIn_G(SL* plistG, int num)
{
	printf("\n<Please enter the coefficient of x and fill out the missing term with zero>\n\n");
	int i = 0;
	DataType x = 0;
	for (i = 0; i <= num; i++)
	{
		printf("Please enter the coefficient of x^%d>>", i);
		scanf("%d", &x);
		plistG->a[i] = x;
	}
	printf("\n");
	printf("g(x) = ");
	for (i = 0; i <= num; i++)
	{
		if (plistG->a[i])
		{
			printf("(%dx^%d)", plistG->a[i], i);
			int j = 0;
			if (i < num)
			{
				printf(" + ");
			}
		}
	}
	printf("\n\n");
}

void SeqListF(SL* plistF)
{
	printf("\n<f(x) is created successfully>\n\n");
	int num = 0;
	printf("Please enter the maximum number of times x>>");
	scanf("%d", &num);
	if (num >= plistF->capacity)
	{
		SeqListCheakCap(plistF, num);
		SeqListTypeIn_F(plistF, num);
	}
	else
	{
		plistF->sz = num;
		SeqListTypeIn_F(plistF, num);
	}
}

void SeqListG(SL* plistG)
{
	printf("\n<g(x) is created successfully>\n\n");
	int num = 0;
	printf("Please enter the maximum number of times x>>");
	scanf("%d", &num);
	if (num >= plistG->capacity)
	{
		SeqListCheakCap(plistG, num);
		SeqListTypeIn_G(plistG, num);
	}
	else
	{
		plistG->sz = num;
		SeqListTypeIn_G(plistG, num);
	}
}

void SeqListPrint(const SL* plistF, const SL* plistG)
{
	printf("\n<The sum of A and B is>\n\n");
	printf("f(x) + g(x) = ");
	int i = 0;
	for (i = 0; i <= (plistF->sz <= plistG->sz ? plistF->sz : plistG->sz); i++)
	{
		if (plistF->a[i] + plistG->a[i])
		{
			printf("(%dx^%d)", plistF->a[i] + plistG->a[i], i);
			if (i < plistF->sz < plistG->sz ? plistF->sz : plistG->sz)
			{
				printf(" + ");
			}
		}
	}
	for (; i <= (plistF->sz > plistG->sz ? plistF->sz : plistG->sz); i++)
	{
		if (plistF->sz > plistG->sz)
		{
			if (plistF->a[i])
			{
				printf("(%dx^%d)", plistF->a[i], i);
				if (i < (plistF->sz > plistG->sz ? plistF->sz : plistG->sz))
				{
					printf(" + ");
				}
			}
		}
		else
		{
			if (plistG->a[i])
			{
				printf("(%dx^%d)", plistG->a[i], i);
				if (i < (plistF->sz > plistG->sz ? plistF->sz : plistG->sz))
				{
					printf(" + ");
				}
			}
		}
	}
	printf("\n\n");
}

void SeqListDestroy(SL* plistF, SL* plistG)
{
	free(plistF->a);
	plistF->a = NULL;
	plistF->sz = plistF->capacity = 0;
	plistF->capacity = 0;
	free(plistG->a);
	plistG->a = NULL;
	plistG->sz = plistG->capacity = 0;
}