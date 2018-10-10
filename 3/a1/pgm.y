%{
#include <stdio.h>
#include <stdlib.h>
%}
%token ID NUM SWITCH CASE DEFAULT BREAK
%right '='
%left '+''-'
%left '*''/'
%%
S       : ST {printf("Input accepted.\n");exit(0);}
;
ST     :    SWITCH '(' ID ')' '{' B '}'
;
B       :    C
        |    C    D
;
C      :     C    C
        |    CASE NUM ':' E ';'
        |    BREAK ';'
;
D      :     DEFAULT    ':' E ';' BREAK ';'
;
E    : ID'='E
    | E'+'E
    | E'-'E
    | E'*'E
    | E'/'E
    | ID
    | NUM
    ;
%%

void main()
{
    printf("Enter the expression: ");
    yyparse();
}

int yyerror()
{
    printf("Invalid");
    return 0;
}







