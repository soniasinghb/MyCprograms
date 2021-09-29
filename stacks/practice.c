#include<stdio.h>
#include<stdlib.h>
int main()
{
    int j=1;
    do{
    int i=1;
        do{
            printf("%d\t",i*j);
            i++;
        }while(i<=10);
    printf("\n");
    j++;
    }while(j<=12);
    return 0;
}