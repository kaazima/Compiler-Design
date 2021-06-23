%{
    #include "y.tab.h"
%}

%%
[0-9]+ return NUM;
[a-zA-Z]+ return ID;
\n return 0;
. return yytext[0];
%%