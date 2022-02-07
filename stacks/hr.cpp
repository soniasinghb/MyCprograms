#include <bits/stdc++.h>

using namespace std;
/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
 int top=-1, i=0;
 char stack[1000];
    while(s[i]) {
    if(s[i]=='{' || s[i]=='[' || s[i]=='(')
        {
            top++;
            stack[top]=s[i];
        }
    else if((stack[top]=='{' && s[i]=='}')||(stack[top]=='(' && s[i]==')')||(stack[top]=='[' && s[i]==']'))
            top--;
    else 
        return "NO";
    }
    if(top>=0)
        return "NO";
    else {
    return "YES";
    }
    i++;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string st, op;
        cin>>st;
        op=isBalanced(st);
        cout<<op<<endl;
    }
}