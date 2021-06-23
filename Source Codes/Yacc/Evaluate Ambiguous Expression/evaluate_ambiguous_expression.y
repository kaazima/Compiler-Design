/* To evaluate the ambiguous arithmetic expression.
E →E+E | E-E |E*E |E/E |(E)| num
*/

%{
    #include<stdio.h>
    #include<stdlib.h>
%}

// Definitions
%token NUM
%left '+' '-'       // Left associativity
%left '*' '/'

// Production Rules
%%
S:E 
{
    printf("Result = %d\n",$$); 
    return 0;
}
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|'('E')' {$$=$2;}
|NUM {$$=$1;}
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