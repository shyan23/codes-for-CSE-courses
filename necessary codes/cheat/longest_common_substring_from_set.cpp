#include<bits/stdc++.h>
using namespace std;
void common_substring(char s1[],char s2[],char s3[])
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);

    int max_len = 0;
    int end = 0;


    for(int i = 0 ; s1[i] != '\0';i++)
    {
        for(int j = 1 ; j <=len1-i;j++)
        {
            char substr[j];
            strncpy(substr,s1+i,j);
            
            substr[j] = '\0';

            int found2 = strstr(s2,substr) != NULL;
            int found3 = strstr(s3,substr) != NULL;

            if(found2 && found3 && j > max_len)
            {
                max_len = j;
                end = i+j;
            }
        }
    }
        if(max_len == 0){
            cout << "no common string\n";
        }else{
            for(int i = end-max_len;i<end;i++)
            {
                printf("%c",s1[i]);
            }
        }
        cout << "\n";
        
}

int main ()
{
    char s1[100];
    char s2[100];
    char s3[100];

    cin >>s1 >> s2 >> s3;

    common_substring(s1,s2,s3);




}