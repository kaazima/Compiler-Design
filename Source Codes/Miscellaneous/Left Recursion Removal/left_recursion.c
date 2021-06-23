/* Program for the removal of left recursion from the given grammar:
	E -> E+T | T
	T -> T*F | F
	F -> id
*/

#include<stdio.h>
#include<string.h>
int main()
{
    int count;
    printf("Enter the number of productions: ");
    scanf("%d",&count);
    char grammar[count][15],nt,first[5],second[5];              // nt=non-terminal
    printf("Enter the grammar: (use '->' for productions)\n");
    for(int i=0;i<count;i++)
        scanf("%s",grammar[i]);
    printf("\nGrammar after the removal of left recursion:\n");
    for(int i=0;i<count;i++)
    {
        int point=3;
        nt=grammar[i][0];
        if(grammar[i][point]==nt)
        {
            int j=0;
            while(grammar[i][point]!='|' && grammar[i][point]!='\0')
                first[j++]=grammar[i][++point];
            first[j-1]='\0';
            if(grammar[i][++point]!='\0')
            {
                int k=0;
                second[k++]=grammar[i][point++];
                printf("%c->%s%c\'",nt,second,nt);  
                printf("\n%c\'->%s%c\'|ɛ\n",nt,first,nt);  
            }
        }
        else
            printf("%s",grammar[i]);
    }
}
