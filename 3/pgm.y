%{
#include<stdio.h>
%}

%token SW OB ID CB NL COB CS NUM Q BR SEM CCB

%%
S: X NL {printf(" Valid ");}
 ;
X: SW OB ID CB NL COB NL CS NUM Q ID SEM NL BR SEM NL CCB
%%

void main()
{
yyparse();
}

int yyerror()
{
printf(" Invalid ");
}




