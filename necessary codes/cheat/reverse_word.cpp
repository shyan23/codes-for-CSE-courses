#include<bits/stdc++.h>
using namespace std;

int main ()
{
    char s[100];
    fgets(s,100,stdin);

    int len = strlen(s);

    int i = len-1;
    char c = ' ';
    int end = 0;
    int start = 0;

    while(i >=0)
    {
        
        for(int j = i; ;j--)
        {
            if(s[j] == c)
            {
                start = j+1;
                end = i;
                break;
            } 
        }

        if(start < 0) start = 0;
        for(int q = start; q <= end;q++)
        {
            cout << s[q];
        }
        cout << " ";
        i = start-2;
    }

}