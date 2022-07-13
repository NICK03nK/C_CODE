#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

int Find_By_Name(Contact* pc,char k_name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, k_name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX_data)
	{
		printf("\n<通讯录已满，无法添加联系人>\n\n");
		return;
	}
	printf("请输入联系人的姓名>>");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入联系人的性别>>");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入联系人的年龄>>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入联系人的电话号码>>");
	scanf("%s", pc->data[pc->count].number);
	printf("请输入联系人的地址>>");
	scanf("%s", pc->data[pc->count].address);
	pc->count++;
	printf("\n<添加联系人成功>\n\n");
}

void DeleteContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("\n<通讯录为空，无需删除联系人>\n\n");
		return;
	}
	char k_name[MAX_name] = { 0 };
	printf("请输入要删除联系人的姓名>>");
	scanf("%s", k_name);
	int pos = Find_By_Name(pc, k_name);
	if (pos == -1)
	{
		printf("\n<要删除的联系人不存在>\n\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("\n<删除联系人成功>\n\n");
}

void SearchContact(const Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("\n<通讯录为空，查找联系人失败>\n\n");
		return;
	}
	char k_name[MAX_name] = { 0 };
	printf("请输入要查找联系人的姓名>>");
	scanf("%s", k_name);
	int pos = Find_By_Name(pc, k_name);
	if (pos == -1)
	{
		printf("\n<通讯录内无此联系人，查找失败>\n\n");
		return;
	}
	printf("\n%-7s\t%-5s\t%-5s\t%-13s\t%-10s\n\n", "姓名", "性别", "年龄", "电话", "地址");
	printf("%-7s\t%-5s\t%-5d\t%-13s\t%-10s\n\n", pc->data[pos].name, pc->data[pos].sex, pc->data[pos].age, pc->data[pos].number, pc->data[pos].address);
}

void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("\n<通讯录为空，修改联系人失败>\n\n");
		return;
	}
	char k_name[MAX_name] = { 0 };
	printf("请输入要修改联系人的姓名>>");
	scanf("%s", k_name);
	int pos = Find_By_Name(pc, k_name);
	if (pos == -1)
	{
		printf("\n<通讯录内无此联系人，修改失败>\n\n");
		return;
	}
	printf("请重新输入联系人的姓名>>");
	scanf("%s", pc->data[pos].name);
	printf("请重新输入联系人的性别>>");
	scanf("%s", pc->data[pos].sex);
	printf("请重新输入联系人的年龄>>");
	scanf("%d", &(pc->data[pos].age));
	printf("请重新输入联系人的电话号码>>");
	scanf("%s", pc->data[pos].number);
	printf("请重新输入联系人的地址>>");
	scanf("%s", pc->data[pos].address);
	printf("\n<修改联系人成功>\n\n");
}

void menu()
{
	printf("\n*********************************\n");
	printf("****     1.Sort_By_Name      ****\n");
	printf("****     2.Sort_By_age       ****\n");
	printf("****     3,Sort_By_number    ****\n");
	printf("*********************************\n\n");
}

int Sort_By_Name(const void* e1, const void* e2)
{
	return strcmp(((PeopInfo*)e1)->name, ((PeopInfo*)e2)->name);
}

int Sort_By_age(const void* e1, const void* e2)
{
	return (((PeopInfo*)e1)->age - ((PeopInfo*)e2)->age);
}

int Sort_By_number(const void* e1, const void* e2)
{
	return strcmp(((PeopInfo*)e1)->number, ((PeopInfo*)e2)->number);
}

void SortContact(const Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("\n<通讯录为空，排序失败>\n\n");
		return;
	}
	int(*SORT[4])(const void*, const void*) = { 0,Sort_By_Name,Sort_By_age,Sort_By_number };
	menu();
	int input = 0;
	printf("请选择排序的标准>>");
	scanf("%d", &input);
	if (input < 1 || input>3)
	{
		printf("\n<选择错误>\n\n");
		return;
	}
	qsort(pc->data, pc->count, sizeof(PeopInfo), SORT[input]);
	printf("\n<排序成功成功>\n\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("\n%-10s\t%-5s\t%-5s\t%-13s\t%-10s\n\n", "姓名", "性别", "年龄", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-10s\t%-5s\t%-5d\t%-13s\t%-10s\n\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].number, pc->data[i].address);
	}
}