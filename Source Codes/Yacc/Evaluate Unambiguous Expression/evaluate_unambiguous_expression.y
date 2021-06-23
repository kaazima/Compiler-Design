/* To evaluate the unambiguous arithmetic expression.
	E → E+T | E-T | T
	T → T*F | T/F | F
	F → num
*/

%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
S:E 
{
    printf("Result = %d\n",$$); 
    return 0;
}
E:E'+'T {$$=$1+$3;}
|E'-'T {$$=$1-$3;}
|T {$$=$1;}
;
T:T'*'F {$$=$1*$3;}
|T'/'F {$$=$1/$3;}
|F {$$=$1;}
;
F:NUM {$$=$1;}
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