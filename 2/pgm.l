%{
#include<stdio.h>
%}

%%
0(10|01)*  {printf("valid"); }
.*  { printf("Not valid"); }

%%

main()
{
yylex();
}

yywrap()
{
}
