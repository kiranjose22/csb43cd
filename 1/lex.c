#include<stdio.h>
#include<string.h>
#include<ctype.h>

int checkforkw(char kw[30])
{
char keywords[32][10] = { "break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","void","while"};	
int i;
for(i=0;i<32;i++)
	{
		if (strcmp(kw,keywords[i])==0)
			return 1;
	}

return 0;
}

int main()
{
FILE *fptr=fopen("input.txt","r");
char checkid[30];
checkid[0]='\0';
char temp[10];
temp[0]='\0';

char ch; int state=0;

  do 
  {
    
	switch(state)
		{
		case 0:ch=fgetc(fptr);		
			if(ch == '<')
				state=1;
			else if(ch== '>')
				state=4;
			else if(ch=='!')
				state=7;
			else if(isdigit(ch))
				//state=9;
				{temp[0]=ch;strcat(checkid,temp);temp[0]='\0';state=9; }
			else if(isalpha(ch))
				{temp[0]=ch;strcat(checkid,temp);temp[0]='\0';state=11; }
			else if(ch=='=')
				{ printf("\n assignment_operator "); state=0;}
			else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
				{ printf("\n arithmetic_operator "); state=0;}
 
			break;
		case 1:ch = fgetc(fptr);
			if(ch=='=')
				{printf("\n relop(LE) "); state=0;}
			else 
				{printf("\n relop(LT) ");fseek(fptr,-1,SEEK_CUR); state=0;}
			break;

		case 4:ch = fgetc(fptr);
                        if(ch=='=')
                                {printf("\n relop(GE) "); state=0;}
                        else 
                                {printf("\n relop(GT) ");fseek(fptr,-1,SEEK_CUR); state=0;}
                        break;
		 case 7:ch = fgetc(fptr);
                        if(ch=='=')
                                {printf("\n relop(NE) "); state=0;}
                        else 
                                {fseek(fptr,-1,SEEK_CUR); state=0;}
                        break;
		case 9:ch = fgetc(fptr);
                        if(isdigit(ch))
                                { state=9;temp[0]=ch;strcat(checkid,temp);temp[0]='\0';}
                        else 
                                {fseek(fptr,-1,SEEK_CUR); state=0;printf("\n num - %s ",checkid);checkid[0]='\0';}
                        break; 
		case 11:ch = fgetc(fptr);
                        if(isalpha(ch))
                                { state=11;temp[0]=ch;strcat(checkid,temp);temp[0]='\0';}
                        else 
                                {fseek(fptr,-1,SEEK_CUR); state=0;

				if(checkforkw(checkid))	
					printf("\n keyword - %s ",checkid);

				else
					printf("\n id - %s ",checkid);





				checkid[0]='\0';}
                        break; 

		
		}
    





 
 
  //  // ch = fgetc(fptr);
  }while(ch != EOF);

fclose(fptr);

}
