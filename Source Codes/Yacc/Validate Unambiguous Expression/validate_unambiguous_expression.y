/* Program to validate the unambiguous arithmetic expression.
	E → E+T | E-T | T
	T → T*F | T/F | F
	F → num
*/

%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token NUM

%%
E:E'+'T
|E'-'T
|T
;
T:T'*'F
|T'/'F
|F
;
F:NUM
;
%%

int main()
{
    printf("Enter an expression:\n");
    yyparse();
    printf("It's a valid expression\n");
    return 0;
}
int yyerror(char *s)
{
    printf("It's an invalid expression\n");
    exit(0);
}