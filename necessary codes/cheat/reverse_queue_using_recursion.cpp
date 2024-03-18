#include <bits/stdc++.h>
using namespace std;

void print(queue<int>q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    
    cout << endl;
}
void sum(queue<int> q,int k)
{
    queue<int>res;
    int n = q.size();

    int sum = 0;
    while(sum <= k && !q.empty())
    {
        sum+= q.front();
        res.push(q.front());
        q.pop();
    }

    while(!res.empty())
    {
        if(sum - res.front() < k) break;
        else res.pop();
    }

    print(res);

}

int main()
{
    queue<int> q;

    int n,k;
    cin >> n>>k;

    while(n--)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    sum(q,k);

}