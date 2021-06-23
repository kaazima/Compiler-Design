/* A lex program to find whether a given number is divisible by 7 or not */
%{
    int num;
%}

%%
[0-9]+ {num=atoi(yytext); if(num%7==0) printf("%d is divisible by 7\n",num); else printf("%d is not divisible by 7\n",num);}
%%

int main(void)
{
    printf("Enter a number\n");
    yylex();
}