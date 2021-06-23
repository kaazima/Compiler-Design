/* lex pgm for */
/* floating point numbers with precision of 4 after the decimal dot */
/* identifiers with length 8, starting with capital letters, ending with 3 digits */
/* keywords used in loops and control statements*/

%%

^[+-]?[0-9]*[.][0-9]{4}$ printf("Floating point number: %s\n",yytext);
^[A-Z][a-zA-Z0-9]{4}[0-9]{3}$ printf("Identifier: %s\n",yytext);
break|case|char|continue|do|const|double|else|for|if|goto|float|int|long|return|switch|void|while printf("Keyword: %s\n",yytext);
.* printf("Unrecognised token: %s\n",yytext);

%%

int main(void)
{
    printf("Enter tokens:\n");
    yylex();
}
