#include <bits/stdc++.h>
using namespace std;

int operation(char a, char b, char sign)
{
    int A = a - '0';
    int B = b - '0';
    switch (sign)
    {
    case '+':
        return A + B;
        break;
    case '-':
        return A - B;
        break;
    case '*':
        return A * B;
        break;
    case '/':
        return A / B;
        break;
    default:
        break;
    }
}

int main()
{
    string c;
    cin >> c;
    stack<int> s; // Change the stack type to int
    for (int i = 0; i < c.length(); i++)
    {
        if (c[i] >= '0' && c[i] <= '9')
        {
            s.push(c[i] - '0'); // Push the numeric value instead of the character
        }
        else
        {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            int res = operation(op2, op1, c[i]);
            s.push(res);
        }
    }

    cout << s.top() << endl;
    return 0;
}
