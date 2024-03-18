#include<bits/stdc++.h>
using namespace std;
void print(int ara[],int n)
{
    for(int i = 0 ; i <=n;i++)
    {
        cout << ara[i] << " ";
    }
    cout << endl;
}
int main ()
{
    int n;
    cin >> n;
    int ara[n];
    for(int i = 0 ; i < n ;i ++)
    {
        cin >> ara[i];
    }
    
    for(int i = 0 ; i < n;i++) // implementing insertion.sort
    {
        int key = ara[i];
        int j = i-1;
    

        while(j >= 0 && ara[j] > key)
        {
            ara[j+1] = ara[j];
            j--;
        }

        ara[j+1] = key;
        
        print(ara,i);

    }
}