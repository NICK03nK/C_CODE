#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>

#define Cap 3
#define Inc_sz 2
#define MAX_name 20
#define MAX_sex 10
#define MAX_number 12
#define MAX_address 30

typedef struct PeopInfo
{
	char name[MAX_name];
	char sex[MAX_sex];
	int age;
	char number[MAX_number];
	char address[MAX_address];
}PeopInfo;

typedef struct Contact
{
	PeopInfo* data;
	int count;
	int capacity;
}Contact;

void InitContact(Contact* pc);

void AddContact(Contact* pc);

void DeleteContact(Contact* pc);

void SearchContact(const Contact* pc);

void ModifyContact(Contact* pc);

void SortContact(const Contact* pc);

void ShowContact(const Contact* pc);

void SaveContactData(const Contact* pc);

void DestroyContact(Contact* pc);