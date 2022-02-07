#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int m,n;
        cin>>m>>n;
        int count=0,sum=0;
        for(int i=m;i<=n;i++)
        {
            while(i!=0)
            {
                sum+=i%10;
                i=i/10;
            }
            if(sum%9==0)
                count++;
        }
        cout<<count<<endl;
    }    
    return 0;
}