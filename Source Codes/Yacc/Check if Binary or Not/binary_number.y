/* To check whether the given binary number is a valid number or not */

%{
    #include<stdio.h>
    #include<stdlib.h>
%}

// Definitions
%token BINARY

// Production Rules
%%
E:BINARY
;
%%

// Main function
int main()
{
    printf("Enter a number:\n");
    yyparse();
    printf("It's a valid binary number\n");
    return 0;
}

// To handle errors
int yyerror(char *s)
{
    printf("It's not a valid binary number\n");
    exit(0);
}