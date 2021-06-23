/* Count the no of characters,words,lines */

%{
	int nchar,nword,nline;
%}

%%
\n {nline++; nchar++;}
[^ \t\n]+ {nword++; nchar+=yyleng;}
. {nchar++;}
%%

int main(void)
{
	printf("Enter the data:\n");
	yylex();
	printf("\nNo of characters: %d\nNo of words: %d\nNo of lines: %d\n",nchar,nword,nline);
}
