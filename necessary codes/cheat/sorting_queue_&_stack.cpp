#include <bits/stdc++.h>
using namespace std;
queue<int>sortqueue(queue<int> &q,int n)      // in O(1) space
{
    for(int i = 0 ; i < n;i++)
    {
        int minindex = -1;
        int minvalue = INT_MAX;

        for(int j = 0 ; j < n-i;j++)
        {
            if(q.front() < minvalue)
            {
                minvalue = q.front();
                minindex = j;
            }
            q.push(q.front());
            q.pop();
        }
    

        for(int k = 0; k < minindex;k++)    // min element er aage shob kisu pichone pathaye dibo
        {
            q.push(q.front());
            q.pop();
        }

        int minelt = q.front();     // min element store kore rekhe dibo
        q.pop();

        for(int i = minindex+1; i < n;i++)  // min element er pore jaa ase oigula shob pichone pathaye dibo
        {
            q.push(q.front());
            q.pop();
        }

        q.push(minelt);     // finally last e minele dhukaye dibo
    
    }

    


    return q;
}
stack<int> sortstack(stack<int> &s)
{
    stack<int> tempa;
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        while (!tempa.empty() && tempa.top() < temp)
        {
            s.push(tempa.top());
            tempa.pop();
        }

        tempa.push(temp);
    }

    return tempa;
}

void print_stack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void print_queue(queue<int>q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}
int main()
{
    queue<int> q;
    stack<int> st;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
        q.push(x);
    }

    stack<int> ans = sortstack(st);
    queue<int>res =  sortqueue(q,n);
    print_stack(ans);
    print_queue(res);

}