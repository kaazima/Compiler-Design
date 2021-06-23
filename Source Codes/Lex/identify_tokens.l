 /*A lex program to identify the following tokens:
	a) Header file b) Keywords c) Relational Operators d) Single line comment e) Multi-line comments	
    f) Identifiers g) Preprocessor Directive h) Data Types i) Digits
 */
 
ID [a-zA-z_][a-zA-Z0-9]*

%%
"#"(include|define|undef|if|else|elif|endif|line|error|warning|region|endregion) printf("Preprocessor Directive: %s\n",yytext);
"<".*".h>" printf("Header file: %s\n",yytext);
"//".* printf("Single line comment\n");
"/*"[^*]*"*/" printf("Multi line comment\n");
>|>=|<|<=|!=|== printf("Relational operator: %s\n",yytext);
int|float|double|char|void printf("Datatype: %s\n",yytext);
auto|break|case|char|continue|do|default|const|double|else|enum|extern|for|if|goto|float|int|long|register|return|signed|static|sizeof|short|struct|switch|typedef|union|void|while|volatile|unsigned printf("Keyword: %s\n",yytext);
{ID} printf("Identifier: %s\n",yytext);
[0-9]+ printf("Digit: %d\n",atoi(yytext));
.* printf("Unrecognised token: %s\n",yytext);
%%

int main(void)
{
    printf("Enter tokens:\n");
    yylex();
}