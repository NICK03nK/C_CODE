#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

typedef struct PeopInfo
{
	char name[20];
	char sex[10];
	int age;
	char number[12];
	char address[30];
}PeopInfo;

typedef struct Contact
{
	PeopInfo data[100];
	int count;
}Contact;