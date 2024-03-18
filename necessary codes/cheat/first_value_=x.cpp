#include<bits/stdc++.h>
using namespace std;
int find_greater(int ara[],int size,int target)
{
    int start = 0;
    int end = size-1;
    int mid ;
    int ans = -1;

    while(start <=end)
    {
        mid = start + (end-start)/2;
        if(ara[mid] >= target)
        {
            ans = ara[mid];
            end = mid-1;
        }else start = mid+1;
    }
    return ans;

    

}

int main ()
{
    int n , target;
    cin >> n >> target;

    int ara[n];
    for(int i = 0 ; i < n;i++)
    {
        cin >> ara[i];
    }

    cout << find_greater(ara,n,target) << endl;

}
