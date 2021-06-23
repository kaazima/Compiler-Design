%{
    #include "y.tab.h"
    extern yylval;
%}

%%
[0-9]+ {yylval=atoi(yytext); return NUM;}
[\t]+ ;
\n return 0;
. return yytext[0];
%%