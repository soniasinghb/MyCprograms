#include<stdio.h>
int m,n;
void findMax(int a[m][n],int m,int n)
{
    int curSum=0, maxSum=0, maxm, maxn;
    for(int i=0;i<m-2;i++)
        for(int j=0;j<n-2;j++){
            curSum=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
            // printf("%d\t",curSum);
            if(curSum>maxSum){
                maxSum=curSum;
                maxm=i;
                maxn=j;
            }
        }
        
    for(int i=maxm; i<(maxm+3);i++){
        for(int j=maxn; j<(maxn+3);j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    
}   

int main(){
    m=3,n=4;
    int a[][4]={{0,1,2,3},{4,5,6,7},{8,9,10,11}};
    findMax(a,m,n);
}