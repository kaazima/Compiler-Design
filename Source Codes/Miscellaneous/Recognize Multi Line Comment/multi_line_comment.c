#include<stdio.h>
#include<string.h>
int main()
{
    char str[200];
    printf("Enter a multi line comment (Enter $ to end the line): \n\n");
    scanf("%[^$]",str);
    int flag=0,len=strlen(str);
    for(int i=0;i<len-1;i++)
    {
        if(str[i]=='/' && str[i+1]=='*' && str[len-2]=='*' && str[len-1]=='/')
        {
            flag=1;
            break;
        }
        else if(str[i]!=' ' && str[i]!='\t')
            break;
    }
    if(flag==0)
        printf("\nIt is not a multi line comment");
    else
        printf("\nIt is a multi line comment");
}
