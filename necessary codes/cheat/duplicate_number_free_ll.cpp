#include <iostream>
#include <set>
using namespace std;

struct node
{
    node *next;
    int data;

    node *head = NULL;
    node *tail = NULL;

    void dhukhano(int n)
    {
        node *a = new node();
        a->next = NULL;
        a->data = n;

        if (head == NULL)
        {
            head = a;
        }
        else
        {
            tail->next = a;
        }
        tail = a;
    }

    void input()
    {
        int n;
        while (cin >> n)
        {
            dhukhano(n);
        }
    }

    node *head1 = NULL;
    node *tail1 = NULL;

    void ans()
    {
        node *tr = head;
        set<int> s;

        while (tr != NULL)
        {
            s.insert(tr->data);
            tr = tr->next; // Add the iteration step
        }

        for (auto it : s)
        {
            node *new_node = new node();
            new_node->data = it;
            if (head1 == NULL)
            {
                head1 = new_node;
            }
            else
            {
                tail1->next = new_node;
            }
            tail1 = new_node;
        }
    }

    void print()
    {
        node *tr = head1;
        while (tr != NULL)
        {
            cout << tr->data << " ";
            tr = tr->next;
        }
        cout << endl;

        // Free memory
        while (head1 != NULL)
        {
            node *temp = head1;
            head1 = head1->next;
            delete temp;
        }
    }
};

int main()
{
    node a;
    a.input();
    a.ans();
    a.print();

    return 0;
}
