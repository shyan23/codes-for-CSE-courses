#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    Stack *node;
    int c;
    Stack *next;

    Stack *head = NULL;
    void Push(int x)
    {

        Stack *new_node = (Stack *)malloc(sizeof(Stack));
        new_node->c = x;
        new_node->next = NULL;

        if (head == NULL)
            head = new_node;
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }
    void Pop()
    {
        if (head == NULL)
            return;
        else
        {
            Stack *temp = head;
            head = head->next;
            free(temp);
        }
    }
    void Peek()
    {
        if (head == NULL)
            return;
        else
            cout << head->c << endl;
    }
    void print()
    {
        Stack *tr = head;
        while (tr != NULL)
        {
            cout << tr->c << " ";
            tr = tr->next;
        }
        cout << endl;
    }
    int Top()
    {
        return head->c;
    }
    bool Empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
};
int evaluatePostfix(string exp)
{

    stack<int> st;

    for (int i = 0; i < exp.size(); ++i)
    {

        if (isdigit(exp[i]))
            st.push(exp[i] - '0');

        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (exp[i])
            {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
        }
    }
    return st.top();
}

// Driver code
int main()
{
    string exp;
    cin >> exp;
    cout << evaluatePostfix(exp) << endl;
    return 0;
}