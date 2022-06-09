#define _CRT_SECURE_NO_WARNINGS 1

#include"contacts_practise.h"

void InitContacts(Contacts* pc)
{
	memset(pc->data, 0, sizeof(pc->data));
	pc->sz = 0;
}

void AddContacts(Contacts* pc)
{
	if (pc->sz == MAX_SIZE)
	{
		printf("\n<通讯录已满，增加失败>\n\n");
		return;
	}
	printf("请输入姓名>>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄>>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别>>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话>>");
	scanf("%s", pc->data[pc->sz].number);
	printf("请输入地址>>");
	scanf("%s", pc->data[pc->sz].address);
	pc->sz++;
	printf("\n<增加成功>\n\n");
}

static FindByName(const Contacts* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContacts(Contacts* pc)
{
	if (pc->sz == 0)
	{
		printf("\n<通讯录为空，无需删除>\n\n");
	}
	printf("请输入要删除人的姓名>>");
	char name[20] = { 0 };
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("\n<通讯录中查无此人，删除失败>\n\n");
	}
	else
	{
		int i = 0;
		for (i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("\n<删除成功>\n\n");
	}
}

void SerchContacts(const Contacts* pc)
{
	if (pc->sz == 0)
	{
		printf("\n<通讯录为空>\n\n");
	}
	printf("请输入要查找人的姓名>>");
	char name[20] = { 0 };
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("\n<通讯录中查无此人>\n\n");
	}
	else
	{
		printf("\n%-6s\t%-5s\t%-5s\t%-13s\t%-10s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("\n%-6s\t%-5d\t%-5s\t%-13s\t%-10s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].number,
			pc->data[pos].address);
	}
}

void ModifContacts(Contacts* pc)
{
	if (pc->sz == 0)
	{
		printf("\n<通讯录为空>\n\n");
	}
	printf("请输入要修改人的姓名>>");
	char name[20] = { 0 };
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("\n<通讯录中查无此人，修改失败>\n\n");
	}
	else
	{
		printf("请重新输入姓名>>");
		scanf("%s", pc->data[pos].name);
		printf("请重新输入年龄>>");
		scanf("%d", &(pc->data[pos].age));
		printf("请重新输入性别>>");
		scanf("%s", pc->data[pos].sex);
		printf("请重新输入电话>>");
		scanf("%s", pc->data[pos].number);
		printf("请重新输入地址>>");
		scanf("%s", pc->data[pos].address);
		printf("\n<修改成功>\n\n");
	}
}

void PrintContacts(const Contacts* pc)
{
	printf("\n%-6s\t%-5s\t%-5s\t%-13s\t%-10s\n", "姓名", "年龄", "性别", "电话", "地址");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("\n%-6s\t%-5d\t%-5s\t%-13s\t%-10s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].number,
			pc->data[i].address);
	}
}