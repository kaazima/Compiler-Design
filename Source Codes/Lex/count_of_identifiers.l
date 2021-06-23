/* A lex program to identify the count of number of identifiers by setting the macros (digits,letters)  */

digit [0-9]
letter [A-Za-z]
%{
        int count=0, discard=0;
%}

%%
        /* Match identifier */
^{letter}({letter}|{digit})* {count++; printf("Identifier\n");}
        /* Discard non-identifiers */
.* {discard++; printf("Not an identifier\n");}
%%

int main(void)
{
        printf("Enter words to find the count of identifiers:\n\n");
        yylex();
        printf("Count of identifiers=%d\n",count);
        return 0;
}
