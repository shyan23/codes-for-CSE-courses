#include<bits/stdc++.h>
using namespace std;

void left_shift(char s[],int n)
{
    n %= strlen(s);
    for(int j = 0 ; j < n;j++)
    {
        char a = s[0];
        for(int i = 0 ; i < strlen(s)-1;i++)
        {
            s[i] = s[i+1];
        }
        s[strlen(s)-1] = a;
        cout << s << endl;
    }
    
}

void right_shift(char s[], int n) {
    n %= strlen(s);
    for (int j = 0; j < n; j++) {
        char a = s[strlen(s) - 1];
        for (int i = strlen(s) - 1; i > 0; i--) {
            s[i] = s[i - 1];
        }
        s[0] = a;
        cout << s << endl;
    }
}



int main ()
{
    int n;
    cin >> n;
    int k;
    cout << "Press 1 for right shift and 0 for left shift\n";
    cin >> k;
    char s[20];
    cin >> s;
    if(k == 0)left_shift(s,n);
    else right_shift(s,n);
}