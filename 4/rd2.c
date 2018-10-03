#include<stdio.h>

char ip[10];
int i;

int S()
{
	if(ip[i]=='c')
	{
		i++;
		if(ip[i]=='d')
		{
			i++;
			if(ip[i]=='\0')
			{
				printf("S->cd\n");
				return 1;
			}
		}
		else
			i--;
	}
	if(A())
	{	if(B())
		{	if(ip[i]=='\0')
			{
				printf("S->AB\n");
				return 1;
			}
		}
		else
			i--;
	}
	if(B())
		{
			if(ip[i]=='\0')
			{
				printf("S->B\n");
				return 1;
			}
		}
	return 0;
}

int A()
{
	if(ip[i]=='a')
	{
		printf("A->a\n");
		i++;
		return 1;
	}
	if(ip[i]=='b')
	{
		printf("A->b\n");
		i++;
		return 1;
	}
	return 0;
}

int B()
{
	if(ip[i]=='c')
	{
		i++;
		if(A())
		{
			if(ip[i]=='d')
			{
				i++;
				printf("B->cAd\n");
				return 1;
			}
		}
	}
	if(ip[i]=='b')
	{
		i++;
		printf("B->b\n");
		return 1;
	}
	return 0;
}

void main()
{
	printf("\nEnter input string:\n");
	scanf("%s",ip);
	if(!S())
		printf("The string is invalid.\n");
	else
		printf("The string is valid.\n");
}
