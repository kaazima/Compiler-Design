// Prefix, suffix, proper prefix, proper suffix, substring, proper substring

#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("Enter a string\n");
    scanf("%s",str);
    int len=strlen(str);
    char a[len][len][50];
    for(int i=0;i<len;i++)
    {
        a[0][i][0]=str[i];
        a[0][i][1]='\0';
    }
    for(int i=1;i<len;i++)                       // Dynamic Programming
        for(int j=0;j<len-i;j++)
            for(int k=0;k<i+1;k++)
            {
                if(k==i)
                {
                    a[i][j][k]=a[0][i+j][0];
                    a[i][j][k+1]='\0';
                }
                else
                    a[i][j][k]=a[i-1][j][k];
            }
            
    printf("\nThe prefixes of %s are \nNULL",str);           // Prefix
    for(int i=0;i<len;i++)
        printf("\t%s",a[i][0]);
        
    printf("\n\nThe proper prefixes of %s are \n",str);           // Proper prefix
    for(int i=0;i<len-1;i++)
        printf("%s\t",a[i][0]);
        
    printf("\n\nThe suffixes of %s are \nNULL",str);              // Suffix
    for(int i=0;i<len;i++)
        printf("\t%s",a[i][len-i-1]);
        
    printf("\n\nThe proper suffixes of %s are \n",str);           // Proper suffix
    for(int i=0;i<len-1;i++)
        printf("%s\t",a[i][len-i-1]);
        
    printf("\n\nThe substrings of %s are \nNULL\n",str);           // Substring
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len-i;j++)
            printf("%s\t",a[i][j]);
        printf("\n");
    }
    
    printf("\nThe proper substrings of %s are \n",str);           // Proper substring
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-i;j++)
            printf("%s\t",a[i][j]);
        printf("\n");
    }
}