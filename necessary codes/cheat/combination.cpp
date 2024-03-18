#include<bits/stdc++.h>
using namespace std;
void comb(int ara[],int data[],int st,int end,int ind,int r)
{
    if(ind == r)            // base case
    {
        for(int i = 0 ; i < r;i++)
        {
            cout << data[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0 ; i <=end && end-i+1 >= r-ind;i++)
    {
        data[ind] = ara[i];
        comb(ara,data,i+1,end,ind+1,r);
    }
}
void print(int ara[],int n,int r)
{
    int data[r];
    comb(ara,data,0,n-1,0,r);
}

int main ()
{
    int n,r;
    cin >> n >> r;
    int ara[n];
    for(int i = 0 ; i < n;i++)
    {
        cin >> ara[i];
    }
    print(ara,n,r);
}