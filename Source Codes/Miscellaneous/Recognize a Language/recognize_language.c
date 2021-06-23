// To recognise the string to accept a* | a*b+ | abb

#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    printf("Enter a string: ");
    scanf("%[^\n]",str);
    int flag=0,len=strlen(str);
    if(len==0 || !strcmp(str,"abb"))
        flag=1;
    else
        for(int i=0;i<len;i++)
            if(flag==0)
            {
                if(str[i]=='b')
                    flag=1;
                else if(str[i]=='a')
                    flag=2;
                else
                    break;
            }
            else if(flag==2 && str[i]=='a')
                continue;
            else if(str[i]!='b')
            {
                flag=0;
                break;
            }
    if(flag==0)
        printf("The entered string is not accepted");
    else
        printf("The entered string is accepted");
}
