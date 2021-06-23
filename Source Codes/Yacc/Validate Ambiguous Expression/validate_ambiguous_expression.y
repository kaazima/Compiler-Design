/* To validate the ambiguous arithmetic expression.
E →E+E | E-E |E*E |E/E |(E) | id | num
*/

%{
    #include<stdio.h>
    #include<stdlib.h>
%}

// Definitions
%token NUM ID
%left '+' '-'       // Left associativity
%left '*' '/'

// Production Rules
%%
E:E'+'E
|E'-'E
|E'*'E
|E'/'E
|'('E')'
|ID
|NUM
;
%%

// Main function
int main()
{
    printf("Enter an expression:\n");
    yyparse();
    printf("It's a valid expression\n");
    return 0;
}

// To handle errors
int yyerror(char *s)
{
    printf("It's an invalid expression\n");
    exit(0);
}