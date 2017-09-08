#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hashing_hw7.h"

int main()
{
	char choose[MAX], name[MAX];
	while(EOF!=scanf("%s", choose))
	{
		if(strcmp(choose,"insert")==0)
		{
			scanf("%s", name);
			insert(name);
		}	
		else if(strcmp(choose,"delete")==0)
		{
			scanf("%s", name);
			delete(name);
		}
		else if(strcmp(choose,"find")==0)
		{
			scanf("%s", name);
			printf("find\t%s\n----------\n", name);
			find(name);
		}
		else
		{
			printf("please enter again.....\n");
			continue;
		}
	}
	return 0;
}
