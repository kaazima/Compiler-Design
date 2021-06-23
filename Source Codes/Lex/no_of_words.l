/* Count the number of words in a line */

%{
        int nword;
%}

%%
[^ \t\n]+ nword++;
\n return 0;
%%

int main(void)
{
	printf("Enter a line of text: ");
        yylex();
        printf("\nNo of words: %d\n",nword);
}
