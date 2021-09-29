#include<stdio.h>
#include<stdlib.h>
void quicksort(int[],int,int);
int split(int[],int,int);
int main()
{
    int arr[]={13,57,25,17,1,90,13};
    int i;

    quicksort(arr,0,6);
    printf("Array after sorting\n");
    for(i=0;i<7;i++)
        printf("%d\t",arr[i]);
    return 0;
}
int split(int a[],int lower,int upper)
{
    int p,q,num,temp;
    p=lower+1;
    q=upper;
    num=a[lower];

    while(q>=p)
    {
        while(a[p]<num)
            p++;
        while(a[q]>num)
            q--;
        if(p<q)
        {
            temp=a[p];
            a[p]=a[q];
            a[q]=temp;
        }
    }
    temp=a[lower];
    a[lower]=a[q];
    a[q]=temp;

    return q;
}
void quicksort(int a[],int lower,int upper)
{
    int i;
    if(upper>lower)
    {
        i=split(a,lower,upper);
        quicksort(a,lower,i-1);
        quicksort(a,i+1,upper);
    }
    else
    exit(0);
}
