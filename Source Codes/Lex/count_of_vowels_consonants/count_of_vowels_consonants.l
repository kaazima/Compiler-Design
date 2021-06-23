/* A lex program to count the number of vowels and consonants in a text file */

letter [a-zA-Z]
vowel [aeiouAEIOU]
%{
    int vCount=0,cCount=0;
%}

%%
{vowel} vCount++;       /* Count vowels */
{letter} cCount++;      /* Count consonants */
EOF return 0;
[^{letter}]             /* Kill other characters */
%%

int main(void)
{
    yyin=fopen("text.txt","r");
    yyout=fopen("output.txt","w");
    yylex();
    fprintf(yyout,"No of vowels=%d\nNo of consonants=%d\n",vCount,cCount);
    fclose(yyin);
    fclose(yyout);
}