#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *next;
    node *prev;
    int data;

    node *head = NULL;
    node *tail = NULL;

    node *create_node(int data, node *prev, node *next)
    {
        node *a = new node;
        a->prev = prev;
        a->data = data;
        a->next = next;

        return a;
    }
    void print()
    {
        node *tr = head;
        while (tr != NULL)
        {
            cout << tr->data << " ";
            tr = tr->next;
        }
        cout << endl;
    }
    void last(int x)
    {
        node *a = create_node(x, tail, NULL);
        if (head == NULL)
        {
            head = a;
            tail = a;
        }
        else
        {
            tail->next = a;
            tail = a;
        }
    }
    void input()
    {
        int n;
        while (cin >> n)
        {
            last(n);
        }
    }

    void rotate_right_shift(int k)
    {
        int cnt = 0;

        node *a = head;
        while (a != NULL)
        {
            cnt++;
            a = a->next;
        }

        k = k % cnt;

        for (int i = 0; i < k; i++)
        {
            int x = tail->data;

            node *tr = tail;

            while (tr->prev != NULL)
            {
                tr->data = tr->prev->data;
                tr = tr->prev;
            }

            head->data = x;

            print();
        }
    }
    void rotate_left_shift(int k)
    {
        int cnt = 0;

        node *a = head;
        while (a != NULL)
        {
            cnt++;
            a = a->next;
        }

        k = k % cnt;

        for (int i = 0; i < k; i++)
        {
            int x = head->data;

            node *tr = head;

            while (tr->next != NULL)
            {
                tr->data = tr->next->data;
                tr = tr->next;
            }

            tail->data = x;

            print();
        }
    }
};

int main()
{
    node a;
    int x;
    cin >> x;
    a.input();
    a.print();
    // a.rotate_right_shift(x);
    //a.rotate_left_shift(x);
}