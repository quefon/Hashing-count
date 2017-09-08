#ifndef HASHING_H_INCLUDE
#define HASHING_H_INCLUDE
#include<stdio.h>
#include<stdlib.h>
#define MAX 100


struct list{
	int count;
	char value[MAX];
	struct list *nextptr;
};
typedef struct list node;
typedef node *link;

node headptr[MAX];

void insert(char* name);
void delete(char* name);
void find(char* name);
unsigned int hash(char* s);

#endif
