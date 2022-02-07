#include<iostream>
#define MAX 10
using namespace std;
struct stack{
    int top;
    int arr[MAX];
}s1;

void push(int val)
{
    if(s1.top>MAX-1)
        cout<<"Stack overflow";
    else{
        s1.top++;
        s1.arr[s1.top]=val;
    }
}
void pop()
{
    int y;
    if(s1.top==-1)
        cout<<"Stack underflow";
    else{
        y=s1.arr[s1.top];
        s1.top--;
    }
    cout<<"Element popped is "<<y;
}
int main()
{
    s1.top=-1;
    push(5);
    push(6);
    pop();
    return 0;
}