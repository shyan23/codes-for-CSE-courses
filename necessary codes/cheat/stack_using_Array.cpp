#include<bits/stdc++.h>
using namespace std;
#define max 10000
struct Stack
{
    int ara[max];
    int top = 0;
    int start = 0;

    void Push(int x)
    {
        if(top == max) return;
        else ara[top++] = x;
    }
    void peek()
    {
        cout << ara[start] << endl;
    }
    void Pop()
    {
        if(start == max) return;
        else start++;
    }
    void print()
    {
        for(int i = start; i < top;i++){
            cout << ara[i] << " ";
        }
        cout << endl;
    }

};

int main ()
{
    Stack s;
    s.Push(10);
    s.print();
    s.Push(11);
    s.Push(12);
    s.Push(123);
    s.print();
    s.Pop();
    s.print();
    s.peek();
}