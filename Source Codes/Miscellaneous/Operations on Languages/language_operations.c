// Union, Intersection, Concatenation

#include<stdio.h>
#include<string.h>
int main()
{
    int len1,len2;
    printf("Enter the no of elements in set1 and set2\n");
    scanf("%d %d",&len1,&len2);
    char set1[len1+1][50],set2[len2+1][50];
    printf("Enter %d elements of set1\n",len1);
    for(int i=0;i<len1;i++)
        scanf("%s",set1[i]);
    printf("Enter %d elements of set2\n",len2);
    for(int i=0;i<len2;i++)
        scanf("%s",set2[i]);

    // Print set1
    printf("\nSet1\t\t: ");
    for(int i=0;i<len1;i++)
        printf("%s   ",set1[i]);

    // Print set2
    printf("\nSet2\t\t: ");
    for(int i=0;i<len2;i++)
        printf("%s   ",set2[i]);

    // Find Union
    printf("\nSet1 ⋃ Set2\t: ");
    for(int i=0;i<len1;i++)
        printf("%s   ",set1[i]);
    for(int i=0;i<len2;i++)
    {
        int flag=0;
        for(int j=0;j<len1;j++)
            if(!strcmp(set2[i],set1[j]))
            {
                flag=1;
                break;
            }
        if(flag==0)
            printf("%s   ",set2[i]);
    }

    // Find Intersection
    printf("\nSet1 ⋂ Set2\t: ");
    for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++)
            if(!strcmp(set1[i],set2[j]))
                printf("%s   ",set1[i]);

    // Find Concatenation
    printf("\nSet1 . Set2\t: ");
    for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++)
            printf("%s%s   ",set1[i],set2[j]);
}