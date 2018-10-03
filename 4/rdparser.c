#include<stdio.h>
#include<string.h>

char input[30];
int i=0;

B()
{




}



S()
{
while(input[i]!='\0')
	{
	if(input[i]=='c')
		{i++;
		if (input[i]=='d')
			{i++;
			if(i==strlen(input)) {printf("\nValid\nS->cd");exit(0);}
			 } 	
		
		}
	A();
	B();
	
	}

}

main()
{


printf("Enter the input string: ");
scanf("%s",&input);

S();

}
