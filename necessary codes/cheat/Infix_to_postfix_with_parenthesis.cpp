// Algorithm :
/*
    1. Get a resulting string
    2. the input is a operand -> push to the resulting string
    3. the input is a operator -> check for precedence in the stack top and make sure dat aint opening braces,
        then until we get opening braces, input all to resulting string and pop , at the end of the loop, pop the braces.
    4. if input is opening braces -> push to stack
    5 .if input is closing braces -> while stack isnt empty and jotokkhhon dhore opening pawa na jaitese, put all to resulting and pop
    Finally, put all the remaining shtiz of stack into res s

*/
#include <bits/stdc++.h>
using namespace std;
bool operrand(char a)
{
    if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z' || a >= '0' && a <= '9')
        return true;
    else
        return false;
}
bool operatorr(char a)
{
    if (a == '/' || a == '+' || a == '-' || a == '*' || a == '^')
        return true;
    else
        return false;
}
int priority(char alpha)
{
    if (alpha == '+' || alpha == '-')
        return 1;

    if (alpha == '*' || alpha == '/')
        return 2;

    if (alpha == '^')
        return 3;

    return 0;
}
bool isopening(char a)
{
    if (a == '(' || a == '{' || a == '[')
        return true;
    else
        return false;
}
bool isclosing(char a)
{
    if (a == ')' || a == '}' || a == ']')
        return true;
    else
        return false;
}
void Infixtopostfix(string q)
{
    stack<char> s;
    string res = " ";
    for (int i = 0; i < q.size(); i++)
    {
        if (operrand(q[i])) // check for operand
        {
            res += q[i];
        }
        else if (operatorr(q[i])) // check for operator
        {
            while (!s.empty() && (priority(s.top()) >= priority(q[i])) && !isopening(s.top()))
            {
                res += s.top();
                s.pop();
            }
            s.push(q[i]);
        }
        else if (isopening(q[i]))
            s.push(q[i]);
        else if (isclosing(q[i]))
        {
            while (!s.empty() && !isopening(s.top()))
            {
                res += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty())
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