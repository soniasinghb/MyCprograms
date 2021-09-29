#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int a[],int l,int m,int h)
{
int i,j,k,c[10000];
i=k=l;
j=m+1;
while(i<=m&&j<=h)
{
 if(a[i]<a[j])
    c[k++]=a[i++];
 else
    c[k++]=a[j++];
}
while(i<=m)
    c[k++]=a[i++];
while(j<=h)
    c[k++]=a[j++];
for(i=l;i<k;i++)
    a[i]=c[i];
}

void mergesort(int a[],int l,int h)
{
int m;
if(l<h)
{
m=(l+h)/2;
mergesort(a,l,m);
mergesort(a,m+1,h);
merge(a,l,m,h);
}
}

main()
{
int a[600],i,j,n;
printf("MERGE SORT\n");
printf("\nenter the size of array:");
scanf("%d",&n);
printf("\nenter the elements one by one\n");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
mergesort(a,0,n-1);
printf("\narray after sorting:");
for(i=0;i<n;i++)
    printf("\t%d",a[i]);
}