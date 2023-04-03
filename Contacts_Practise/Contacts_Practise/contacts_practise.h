#pragma once

#include<stdio.h>
#include<string.h>

#define MAX_SIZE 10
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_NUMBER 12
#define MAX_ADDRESS 20

typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char number[MAX_NUMBER];
	char address[MAX_ADDRESS];
}PeoInfo;

typedef struct Contacts
{
	PeoInfo data[MAX_SIZE];
	int sz;
}Contacts;

void InitContacts(Contacts* pc);

void AddContacts(Contacts* pc);

void DelContacts(Contacts* pc);

void SerchContacts(const Contacts* pc);

void ModifContacts(Contacts* pc);

void PrintContacts(const Contacts* pc);