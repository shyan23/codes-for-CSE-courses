#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void subset(int ara[],int n)
{
    cout <<"[]";
    for(int mask = 0 ; mask < (1 << n);++mask)
    { 
        for(int i = 0 ; i < n ; i++)
        {
            if((mask & (1 << i)))
            {
            cout << ara[i] << " ";
            }
        }
        cout << endl;
    } 
}
int main ()
{
    int n;
    cin >> n ;
    int ara[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> ara[i];
    }
    subset(ara,n);
}