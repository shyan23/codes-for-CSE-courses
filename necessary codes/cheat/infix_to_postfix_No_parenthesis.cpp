#include <bits/stdc++.h>
using namespace std;
bool high(char a, char b)
{
    if(a == '/') return true;
    else if(a == '*' && b != '/') return true;
    else if(a == '+' && b == '-') return true;
    else return false;
}
void Infixtopostfix(string q)
{
    stack<char> s;
    string res = " ";
    for (int i = 0; i < q.size(); i++)
    {
        if (q[i] >= '0' && q[i] <= '9')
        {
            res += q[i];
        }
        else
        {
            while (!s.empty() && high(s.top(), q[i]))
            {
                res += s.top();
                s.pop();
            }
            s.push(q[i]);
        }
    }
    while(!s.empty())
    {
        res += s.top();
        s.pop();
    }
    cout << res << endl;
}
int main()
{
    string i;
    cin >> i;
    Infixtopostfix(i);
}