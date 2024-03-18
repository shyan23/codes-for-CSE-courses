#include <stdio.h>

void char_swap(char ch1[], char ch2[])
{
    char temp[10001];
    int i = 0;
    while (ch1[i] != '\0')
    {
        temp[i] = ch1[i];
        i++;
    }
    temp[i] = '\0';
    i = 0;
    while (ch2[i] != '\0')
    {
        ch1[i] = ch2[i];
        i++;
    }
    ch1[i] = '\0';
    i = 0;
    while (temp[i] != '\0')
    {
        ch2[i] = temp[i];
        i++;
    }
    ch2[i] = '\0';
}
int string_cmp_less(char ch1[], char ch2[])
{
    int flag = 0;
    for (int i = 0; ch1[i] != '\0' || ch2[i] != '\0'; i++)
    {
        if (ch1[i] < ch2[i])
        {
            flag++;
            break;
        }
        else if (ch1[i] > ch2[i])
            break;
    }
    return flag;
}
int main()
{
    int n;
    scanf("%d", &n);
    char ch1[n][1001] = {{'\0'}};
    int ara[n];
    for (int i = 0; i < n; i++)
    {
        ara[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", ch1[i]);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (string_cmp_less(ch1[ara[j]], ch1[ara[j - 1]]))
            {
                int temp = ara[j];
                ara[j] = ara[j - 1];
                ara[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", ch1[ara[i]]);
    }
    return 0;
}
