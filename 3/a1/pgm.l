
%{
    #include "y.tab.h"
%}
alpha [A-Za-z]
digit [0-9]
%%
[ \t\n] 
"switch"   { return SWITCH; }
"case" { return CASE; }
"break" { return BREAK; }
"default" { return DEFAULT; }
{digit}+    { return NUM; }
{alpha}({alpha}|{digit})*   { return ID; }
.    { return yytext[0]; }
%%
int yywrap()
{
    return 0;
}
