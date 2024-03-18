#include <bits/stdc++.h>
using namespace std;

struct ll
{
    struct node
    {
        node *next;
        int data;
    };

    node *head = NULL;
    node *tail = NULL;

    node *create_node(node *next, int x)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = x;
        new_node->next = next;
    }
    void Add_node_at_start(int x)
    {
        node *a = create_node(head, x);
        if (head == NULL)
        {

            head = a;
            tail = a;
        }
        else
        {
            head = a;
        }
    }
    void Add_node_at_back(int x)
    {
        node *a = create_node(NULL, x);
        if (tail != NULL)
        {
            tail->next = a;
            tail = a;
        }
        else
        {
            head = a;
            tail = a;
        }
    }
    void delete_at_front()
    {
        if (head == NULL)
            return;
        else
        {
            node *temp = head;
            head = head->next;
            free(head);
        }
    }
    void delete_at_last()
    {
        if (tail == NULL)
            return;
        else
        {
            node *tr = head;
            while (tr->next != tail)
            {
                tr = tr->next;
            }

            node *temp = tr;
            tail = tr;
            tr->next = NULL;
            free(temp->next);
        }
    }
    void add_node_after_data_x(int x,int y)
    {
        if (head == NULL)
            return;
        else
        {
            node *tr = head;
            while (tr->data != x)
            {
                tr = tr->next;
            }
            node *temp = tr->next;
            node *a = create_node(temp, y);
            tr->next = a;
        }
    }
void delete_node_at_data_x(int x)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (head->data == x)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        if (head == NULL)
        {
            tail = NULL;
        }
        return;
    }

    node *tr = head;
    while (tr->next != NULL && tr->next->data != x)
    {
        tr = tr->next;
    }

    if (tr->next == NULL)
    {
        cout << "Element not found in the list." << endl;
        return;
    }

    node *temp = tr->next;
    tr->next = tr->next->next;
    free(temp);

    if (tr->next == NULL)
    {
        tail = tr; // If the last element is deleted
    }
}

    void print()
    {
        node* tr = head;
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
    ll link;
    link.Add_node_at_start(10);
    link.Add_node_at_back(15);
    link.print();
    link.add_node_after_data_x(10,19);
    link.print();
    link.delete_node_at_data_x(19);
    link.print();
}