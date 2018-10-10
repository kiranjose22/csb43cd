#include<stdio.h>
#include<ctype.h>
#include<string.h>

char input[20][30];
char nt[20];
int n;
char fst[20][30];
char temp[30];

main()
{

printf("\nNo of non terminals: ");
scanf("%d",&n);
printf("\nEnter rules: ");
for(int i=0;i<n;i++)
	{
	scanf("%s",&input[i]);
	nt[i]=input[i][1];
	}

}


first(char nter)
{int pos;
	for(int i=0;i<n;i++)
	{
	if(nter == nt[i])
		{pos=i; break;}
	}
for(int j=3;input[pos][j]!='\0';j++)
	{ if(input[pos][j]=='/'){j++;break;}
		if(isupper(input[pos][j])
		{ first(input[pos][j]); }
		else 
		{
		
		}
	}

}

