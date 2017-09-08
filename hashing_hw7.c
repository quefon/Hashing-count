#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hashing_hw7.h"

unsigned int hash(char* s)
{
	int i, n=5381;
	for(i=0; s[i]; i++)
		n = ((n<<5)+n)+s[i];
	return n;
}
void insert(char* name)
{
	link newnode, currentPtr;
	int index = hash(name)%MAX;
	newnode = malloc(sizeof(node));
	strcpy(newnode->value,name);
	newnode->count=1;
	newnode->nextptr = NULL;

	currentPtr = &headptr[index];
	while(currentPtr!=NULL)
	{
		if(strcmp(currentPtr->value,name)==0)
		{
			currentPtr->count++;
			return ;
		}
		else
			currentPtr = currentPtr->nextptr;		
	}
	currentPtr = &headptr[index];
	if(currentPtr->nextptr == NULL)
		headptr[index].nextptr = newnode;
		//currentPtr->nextptr = newnode;   //effort is same!
	else
	{
		while(currentPtr->nextptr!=NULL)
			currentPtr = currentPtr->nextptr;
		currentPtr->nextptr = newnode;
	}
}
void delete(char* name)
{
	int index = hash(name)%MAX;
	link currentPtr;
	currentPtr = &headptr[index];
	while(currentPtr!=NULL)
	{
		if(strcmp(currentPtr->value, name)==0)
		{
			if(currentPtr->count <= 0) return ;
			else
				currentPtr->count-=1;
		}
		currentPtr = currentPtr->nextptr;
	}
}
void find(char* name)
{
	int index = hash(name)%MAX;
	link currentPtr; 
	currentPtr = &headptr[index];
	
	while(currentPtr!=NULL)
	{
		if(strcmp(currentPtr->value,name)==0 && currentPtr->count>=1)
		{
			printf("%s\t%d\n",currentPtr->value,currentPtr->count);
			printf("----------\n");
			return ;
		}	
		currentPtr = currentPtr->nextptr;
	}
	printf("Not\tfound!\n----------\n");
}
