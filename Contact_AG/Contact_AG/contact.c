#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void CheckCapacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeopInfo* tmp = realloc(pc->data, (pc->capacity + Inc_sz) * sizeof(PeopInfo));
		if (tmp == NULL)
		{
			printf("CheckCapacity:>%s", strerror(errno));
			return;
		}
		else
		{
			pc->data = tmp;
			pc->capacity += Inc_sz;
			printf("\n<���ݳɹ�>\n\n");
		}
	}
}

void LoadContactData(Contact* pc)
{
	FILE* pfRead = fopen("Contact_Data.txt", "rb");
	if (pfRead == NULL)
	{
		perror("LoadContactData");
		return;
	}
	PeopInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeopInfo), 1, pfRead) == 1)
	{
		CheckCapacity(pc);
		pc->data[pc->count] = tmp;
		pc->count++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

void InitContact(Contact* pc)
{
	assert(pc);
	pc->data = (PeopInfo*)calloc(Cap, sizeof(PeopInfo));
	if (pc->data == NULL)
	{
		printf("InitContact:>%s", strerror(errno));
		return;
	}
	pc->count = 0;
	pc->capacity = Cap;
	LoadContactData(pc);
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
	CheckCapacity(pc);
	printf("��������ϵ�˵�����>>");
	scanf("%s", pc->data[pc->count].name);
	printf("��������ϵ�˵��Ա�>>");
	scanf("%s", pc->data[pc->count].sex);
	printf("��������ϵ�˵�����>>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("��������ϵ�˵ĵ绰����>>");
	scanf("%s", pc->data[pc->count].number);
	printf("��������ϵ�˵ĵ�ַ>>");
	scanf("%s", pc->data[pc->count].address);
	pc->count++;
	printf("\n<�����ϵ�˳ɹ�>\n\n");
}

void DeleteContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("\n<ͨѶ¼Ϊ�գ�����ɾ����ϵ��>\n\n");
		return;
	}
	char k_name[MAX_name] = { 0 };
	printf("������Ҫɾ����ϵ�˵�����>>");
	scanf("%s", k_name);
	int pos = Find_By_Name(pc, k_name);
	if (pos == -1)
	{
		printf("\n<Ҫɾ������ϵ�˲�����>\n\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("\n<ɾ����ϵ�˳ɹ�>\n\n");
}

void SearchContact(const Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("\n<ͨѶ¼Ϊ�գ�������ϵ��ʧ��>\n\n");
		return;
	}
	char k_name[MAX_name] = { 0 };
	printf("������Ҫ������ϵ�˵�����>>");
	scanf("%s", k_name);
	int pos = Find_By_Name(pc, k_name);
	if (pos == -1)
	{
		printf("\n<ͨѶ¼���޴���ϵ�ˣ�����ʧ��>\n\n");
		return;
	}
	printf("\n%-7s\t%-5s\t%-5s\t%-13s\t%-10s\n\n", "����", "�Ա�", "����", "�绰", "��ַ");
	printf("%-7s\t%-5s\t%-5d\t%-13s\t%-10s\n\n", pc->data[pos].name, pc->data[pos].sex, pc->data[pos].age, pc->data[pos].number, pc->data[pos].address);
}

void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("\n<ͨѶ¼Ϊ�գ��޸���ϵ��ʧ��>\n\n");
		return;
	}
	char k_name[MAX_name] = { 0 };
	printf("������Ҫ�޸���ϵ�˵�����>>");
	scanf("%s", k_name);
	int pos = Find_By_Name(pc, k_name);
	if (pos == -1)
	{
		printf("\n<ͨѶ¼���޴���ϵ�ˣ��޸�ʧ��>\n\n");
		return;
	}
	printf("������������ϵ�˵�����>>");
	scanf("%s", pc->data[pos].name);
	printf("������������ϵ�˵��Ա�>>");
	scanf("%s", pc->data[pos].sex);
	printf("������������ϵ�˵�����>>");
	scanf("%d", &(pc->data[pos].age));
	printf("������������ϵ�˵ĵ绰����>>");
	scanf("%s", pc->data[pos].number);
	printf("������������ϵ�˵ĵ�ַ>>");
	scanf("%s", pc->data[pos].address);
	printf("\n<�޸���ϵ�˳ɹ�>\n\n");
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
		printf("\n<ͨѶ¼Ϊ�գ�����ʧ��>\n\n");
		return;
	}
	int(*SORT[4])(const void*, const void*) = { 0,Sort_By_Name,Sort_By_age,Sort_By_number };
	menu();
	int input = 0;
	printf("��ѡ������ı�׼>>");
	scanf("%d", &input);
	if (input < 1 || input>3)
	{
		printf("\n<ѡ�����>\n\n");
		return;
	}
	qsort(pc->data, pc->count, sizeof(PeopInfo), SORT[input]);
	printf("\n<����ɹ��ɹ�>\n\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("\n%-10s\t%-5s\t%-5s\t%-13s\t%-10s\n\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-10s\t%-5s\t%-5d\t%-13s\t%-10s\n\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].number, pc->data[i].address);
	}
}

void SaveContactData(const Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("Contact_Data.txt", "wb");
	if (pfWrite == NULL)
	{
		perror("SaveContactData");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(PeopInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}

void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}