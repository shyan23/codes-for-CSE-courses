#include<bits/stdc++.h>
using namespace std;

void binary_search(int s,int e,int n,int f,int ara[])
{
    
    int mid;
    if(s > e) {
        printf("-1\n");
        return;
    }   
    mid = (s + e)/2;

    if(ara[mid] == f) printf("%d\n",mid);
    else if(ara[mid] > f)
    {
        binary_search(s,mid-1,n,f,ara);
    }else
    {
        binary_search(mid+1,e,n,f,ara);
    }
    
}
    int main ()
    {
        int n,f;
        scanf("%d%d",&n,&f);
        int ara[n];
        for(int i = 0 ; i < n; i++){
            scanf("%d",&ara[i]);
        }
        sort(ara,ara+n);
        binary_search(0,n-1,n,f,ara);



    }

