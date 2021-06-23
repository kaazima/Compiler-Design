%{
    #include "y.tab.h"
%}

%%
[01]+ return BINARY;
[\t]+ ;
. return yytext[0];
\n return 0;
%%