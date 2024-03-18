#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define prnt FOR(i,0,n) cout << ara[i] << " ";

int minindex(int ara[], int n, int ind)
{
    int min_index = ind;
    FOR(i, min_index + 1, n)
    {
        if (ara[i] < ara[min_index])
        {
            min_index = i;
        }
    }

    return min_index;
}
void selectionsort(int ara[], int n)
{
    FOR(i,0,n)
    {
        int indi = i;
        if(minindex(ara,n,i) != i)
        {
            swap(ara[i],ara[minindex(ara,n,i)]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int ara[n];
    FOR(i, 0, n)
    {
        cin >> ara[i];
    }

    selectionsort(ara, n);

    prnt;


}
