%{
#include<stdio.h>
%}

%token SW OB CB ID EQ NL COB CCB CS Q BR SEM NUM
%left '+''-'
%left '*''/'
%left '('')'

%%

S: X NL {printf(" Valid ");}
 ;

X: SW OB ID CB NL COB NL C CCB
 ;

C: C C
 | CS NUM Q ID EQ E SEM NL BR SEM NL
 ;

E : E'+'E
  | E'-'E
  | E'*'E
  | E'/'E
  | '('E')'
  | NUM
  | NL
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






