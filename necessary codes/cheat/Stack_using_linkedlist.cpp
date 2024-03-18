#include<bits/stdc++.h>
using namespace std;
struct Stack
{
    Stack* node;
    int data;
    Stack* next;

    Stack* head = NULL;
    void Push(int x)
    {

        Stack* new_node = (Stack*) malloc(sizeof(Stack));
        new_node->data = x;
        new_node->next = NULL;

        if(head == NULL) head = new_node;
        else
        {
            new_node->next = head;
            head = new_node;

        }
    }
    void Pop()
    {
        if(head == NULL) return;
        else
        {
            Stack* temp = head;
            head = head->next;
            free(temp);
        }
    }
    void Peek()
    {
        if(head == NULL) return;
        else cout << head->data << endl;
    }
    void print()
    {
        Stack* tr = head;
        while(tr != NULL)
        {
            cout << tr->data << " ";
            tr = tr->next;
        }
        cout << endl;
    }
};
int main ()
{
    Stack ll;
    ll.Push(10);
    ll.print();
    ll.Push(11);
    ll.print();
    ll.Push(12);
    ll.print();
    ll.Push(13);
    ll.print();
    ll.Pop();
    ll.print();
    ll.Peek();
}