/* Program for the removal of left factoring from the given grammar:
	E -> E+T | E*T | T
*/

#include <stdio.h>
int main()
{
    int count;
    printf("Enter the number of productions: ");
    scanf("%d",&count);
    char grammar[count][15],first[10][10],second[10][10],findex=0,sindex=0,nt;
    printf("Enter the grammar: (use '->' for productions)\n");
    for(int i=0;i<count;i++)
        scanf("%s",grammar[i]);
    printf("\nGrammar after the removal of left factoring:\n");
    for(int i=0;i<count;i++)
    {
        int point=2;
        nt=grammar[i][0];
        while(grammar[i][++point]!='\0')
        {
            if(grammar[i][point]==grammar[i][3])
            {
                int jf=0;
                while(grammar[i][point]!='\0' && grammar[i][point]!='|')
                    first[findex][jf++]=grammar[i][++point];
                first[findex++][jf-1]='\0';
            }
            else
            {
                int js=0;
                while(grammar[i][point]!='\0' && grammar[i][point]!='|')
                    second[sindex][js++]=grammar[i][point++]; 
                second[sindex++][js]='\0';
            }
        }
        printf("%c->%c%c\'",nt,grammar[0][3],nt);
        for(int i=0;i<sindex;i++)
            printf("|%s",second[i]);
        printf("\n%c\'->%s",nt,first[0]);
        for(int i=1;i<findex;i++)
            printf("|%s",first[i]);
    }
}
