#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)  for(int i = a ; i < b;i++)


void search(int ara[],int n)
{
    int l = 0;
    int r = n-1;

    int mid ;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(ara[mid] > 0) r = mid-1;
        else if(ara[mid] < 0) break;
    }
    cout << (n-mid-1) << endl;
}
int main ()
{
    int n;
    cin >>n;
    int ara[n];

    FOR(i,0,n)
    {
        cin >> ara[i];
    }

    if(ara[0] > 0 && ara[n-1] >0) cout << n << endl;
    else if(ara[0] < 0 && ara[n-1]<0) cout << "0" << endl;
    else
        search(ara,n);
}