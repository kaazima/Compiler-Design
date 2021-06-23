/* A lex program to display the words entered by using ECHO  */

%%
	/* Match everything except newline */
.	ECHO;
	/* Match newline */
\n	ECHO;
%%

int yywrap(void)
{
	return 1;
}

int main(void)
{
	printf("Enter words:\n");
	yylex();
	return 0;
}