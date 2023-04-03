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
		printf("\n<ͨѶ¼����������ʧ��>\n\n");
		return;
	}
	printf("����������>>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������>>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�>>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰>>");
	scanf("%s", pc->data[pc->sz].number);
	printf("�������ַ>>");
	scanf("%s", pc->data[pc->sz].address);
	pc->sz++;
	printf("\n<���ӳɹ�>\n\n");
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
		printf("\n<ͨѶ¼Ϊ�գ�����ɾ��>\n\n");
	}
	printf("������Ҫɾ���˵�����>>");
	char name[20] = { 0 };
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("\n<ͨѶ¼�в��޴��ˣ�ɾ��ʧ��>\n\n");
	}
	else
	{
		int i = 0;
		for (i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("\n<ɾ���ɹ�>\n\n");
	}
}

void SerchContacts(const Contacts* pc)
{
	if (pc->sz == 0)
	{
		printf("\n<ͨѶ¼Ϊ��>\n\n");
	}
	printf("������Ҫ�����˵�����>>");
	char name[20] = { 0 };
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("\n<ͨѶ¼�в��޴���>\n\n");
	}
	else
	{
		printf("\n%-6s\t%-5s\t%-5s\t%-13s\t%-10s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("\n<ͨѶ¼Ϊ��>\n\n");
	}
	printf("������Ҫ�޸��˵�����>>");
	char name[20] = { 0 };
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("\n<ͨѶ¼�в��޴��ˣ��޸�ʧ��>\n\n");
	}
	else
	{
		printf("��������������>>");
		scanf("%s", pc->data[pos].name);
		printf("��������������>>");
		scanf("%d", &(pc->data[pos].age));
		printf("�����������Ա�>>");
		scanf("%s", pc->data[pos].sex);
		printf("����������绰>>");
		scanf("%s", pc->data[pos].number);
		printf("�����������ַ>>");
		scanf("%s", pc->data[pos].address);
		printf("\n<�޸ĳɹ�>\n\n");
	}
}

void PrintContacts(const Contacts* pc)
{
	printf("\n%-6s\t%-5s\t%-5s\t%-13s\t%-10s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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