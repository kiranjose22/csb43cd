%{
#include "y.tab.h"
%}

id [a-zA-Z]([a-zA-Z]|[0-9])*
num [0-9]+
	
%%
"switch" {return SW;}
"case" {return CS;}
"break" {return BR;}
"(" { return OB;}
{id} {return ID;}
"\n" {return NL; }
")" {return CB; }
"{" {return COB;}
{num} {return NUM;}
":" {return Q;}
"}" { return CCB;}
";" { return SEM; }
"=" {return EQ;}
.      {return yytext[0];}
%%

int yywrap()
{return 0;
} 
