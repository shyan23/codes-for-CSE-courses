#include <bits/stdc++.h>
using namespace std;
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
            case '^':
                st.push(pow(val2,val1));
            }
        }
    }
    return st.top();
}

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
string Infixtopostfix(string q)
{
    stack<char> s;
    string res = "";
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
    return res;
}

int main()
{
    string exp;
    cin >> exp;
    string r = Infixtopostfix(exp);
    cout<< evaluatePostfix(r);
    return 0;
}