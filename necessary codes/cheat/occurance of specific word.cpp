#include<bits/stdc++.h>
using namespace std;

int word_count(char* str, char* word)
{
    int slen = strlen(str);
    int wlen = strlen(word);
    int end_checking  = slen - wlen +1;
    int count = 0;

    for(int i = 0 ; i < end_checking;i++)
    {
        int word_found = 1;
        for(int j = 0 ; j < wlen;j++)
        {
            
            if(word[j] != str[i+j])
            {
                word_found = 0;
                break;
            }
        }
        if(word_found)count++;
        
    }
    return count;
}
int main ()
{
    char str[200];
    char word[100];
    fgets(str,200,stdin);
    fgets(word,100,stdin);
    cout << word_count(str,word);
}
