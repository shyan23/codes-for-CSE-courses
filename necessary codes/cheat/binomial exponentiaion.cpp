#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll bigmod(ll a ,ll b)
{
    if (b == 0) return  1 ;
    else
    {

        ll res = bigmod(a,b/2);
        if(b % 2 == 0) return res * res ;
        else return res * res * a;
    }
}

int main ()
{
    ll a ,b;
    cin >> a >> b;
    cout << bigmod(a,b) << endl;

}
