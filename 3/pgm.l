%{
#include "y.tab.h"
%}

id [a-zA-Z]([a-zA-Z]|[0-9])*
num [0-9]+	
%%
"switch" {return SW;}
"(" { return OB;}
{id} {return ID;}
"\n" {return NL; }
")" {return CB; }
"{" {return COB;}
"case" {return CS;}
{num} {return NUM;}
":" {return Q;}
"break" {return BR;}
"}" { return CCB;}
";" { return SEM; }
%%

int yywrap()
{return 0;
} 
