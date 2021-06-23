#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("Enter a single line comment: ");
    scanf("%[^\n]",str);
    int flag=0;
    for(int i=0;i<strlen(str)-1;i++)
    {
        if(str[i]=='/' && str[i+1]=='/')
        {
            flag=1;
            break;
        }
        else if(str[i]!=' ' && str[i]!='\t')
            break;
    }
    if(flag==0)
        printf("It is not a single line comment");
    else
        printf("It is a single line comment");
}
