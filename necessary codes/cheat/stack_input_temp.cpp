#include <iostream>
#include <stack>

using namespace std;

void print(stack<int> &s)
{
    if (s.empty())
        return; // base case
    else
    {
        int top = s.top();
        s.pop();

        print(s);

        cout << top << " ";

    }
}
void solve(int ara[], int n)
{
    stack<int> inputstack;
    stack<int> tempstack;

    for (int i = 0; i < n; i++)
    {
        inputstack.push(ara[i]);
    }

    while (!inputstack.empty())
    {
        int currentelement = inputstack.top();
        inputstack.pop();
        if (tempstack.empty() || currentelement >= tempstack.top())
        {
            tempstack.push(currentelement);
        }
        else
        {
            while (!tempstack.empty() && currentelement < tempstack.top())
            { // Corrected condition
                inputstack.push(tempstack.top());
                tempstack.pop();
            }
            tempstack.push(currentelement);
        }
    }

    print(tempstack);
}

int main()
{
    int n;
    cin >> n;
    int ara[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i];
    }
    solve(ara, n);
}
