%{
#include<stdio.h>
%}

%token SW OB CB ID EQ NL COB CCB CS Q BR SEM NUM

%%

S: X NL {printf(" Valid ");}
 ;
X: SW OB ID CB NL COB NL CS NUM Q ID EQ NUM SEM NL BR SEM NL CCB
 ;

%%

int yyerror()
{
printf(" Invalid ");
}

void main()
{
yyparse();
}






