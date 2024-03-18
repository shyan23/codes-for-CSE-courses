#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *next;
    node *prev;
    int data;

    node *head = NULL;
    node *tail = NULL;

    node *create_node(int x, node *prev, node *next)
    {
        node *a = new node;
        a->data = x;
        a->prev = prev;
        a->next = next;

        return a;
    }

    void addatthenext(int x)
    {
        node *a = create_node(x, tail, head);
        if (head == NULL)
        {
            head = a;
            tail = a;
        }
        else
        {
            tail->next = a;
            head->prev = a;
            tail = a;
        }
    }
    void addnodeatfirst(int x)
    {
        node* a = create_node(x,tail->prev,head->prev);
        
        if(head ==NULL)
        {
            tail = a;
            head = a;

        }else{
            head = a;
        }
    }


    void deletenode(int k)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        node *tr = head;
        for (int i = 0; i < k - 1; i++)
        {
            tr = tr->next;
        }

        if (tr == head)
        {
            head = tr->next;
        }

        tr->prev->next = tr->next;
        tr->next->prev = tr->prev;

        delete tr;
    }
};

int main()
{
    node a;
    a.addatthenext(10);
    a.addatthenext(11);
    a.addatthenext(12);
    a.addatthenext(14);
    a.addatthenext(15);
    a.deletenode(3);
    a.addnodeatfirst(101);

    node *tr = a.head;
    int i = 0;
    while (i < 10)
    {
        cout << tr->data << " ";
        tr = tr->next;
        i++;
    }
    cout << endl;

    return 0;
}
