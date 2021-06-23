#include<stdio.h>
#include<string.h>
int main()
{
    char str[40];
    printf("Enter a string to check if it is an identifier or not: ");
    scanf("%[^\n]",str);
    int flag=0,len=strlen(str);
    if(!(strcmp(str,"auto") && strcmp(str,"break") && strcmp(str,"case") && strcmp(str,"char") && strcmp(str,"continue") && strcmp(str,"do") && strcmp(str,"default") && strcmp(str,"const") && strcmp(str,"double") && strcmp(str,"else") && strcmp(str,"enum") && strcmp(str,"extern") && strcmp(str,"for") && strcmp(str,"if") && strcmp(str,"goto") && strcmp(str,"float") && strcmp(str,"int") && strcmp(str,"long") && strcmp(str,"register") && strcmp(str,"return") && strcmp(str,"signed") && strcmp(str,"static") && strcmp(str,"sizeof") && strcmp(str,"short") && strcmp(str,"struct") && strcmp(str,"switch") && strcmp(str,"typedef") && strcmp(str,"union") && strcmp(str,"void") && strcmp(str,"while") && strcmp(str,"volatile") && strcmp(str,"unsigned")))
        flag=1;
    else if(len>31 || (!((str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z') || str[0]=='_')))
        flag=1;
    else
        for(int i=1;i<len;i++)
            if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9') || str[i]=='_' )
                continue;
            else
            {
                flag=1;
                break;
            }
    if(flag==1)
        printf("It is not an identifier");
    else
        printf("It is an identifier");
}
