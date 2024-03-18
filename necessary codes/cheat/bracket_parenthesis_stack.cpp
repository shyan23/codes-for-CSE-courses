#include<bits/stdc++.h>
using namespace std;

void solve(string s)
{
    stack<char>st;

    for(int i = 0 ; s[i] != '\0';i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[' || st.empty())
        {
            st.push(s[i]);
        }else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(s[i] == ')' && st.top() == '(')st.pop();
            else if(s[i] == '}' && st.top() == '{')st.pop();
            else if(s[i] == ']' && st.top() == '[')st.pop();
            else st.push(s[i]);
            
        }
    }

    if(!st.empty()) cout << "NO\n";
    else cout <<"YES\n";
}
int main ()
{
    string s;
    cin >> s;
    if(s.empty()) cout <<"NO\n";
    else solve(s);
}