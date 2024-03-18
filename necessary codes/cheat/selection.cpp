#include<stdio.h>
void print(int ara[],int n)
{
    for(int i = 0 ; i<n;i++)
    {
        printf("%d ",ara[i]);
    }
}
void selection(int ara[],int n)
{
    int min,temp,min_index;
    for(int i = 0; i<n;i++)
    {
        min = ara[i];
        min_index = i;
        for(int j = i+1;j<n;j++)
        {
            if(ara[j] < min)
            {
             min = ara[j];
             min_index = j;
            }
        }
        printf("the minimum is : %d\n",min);

        temp = ara[i];
        ara[i] = ara[min_index];
        ara[min_index] = temp;
        
        printf("the array now is : ");
        print(ara,n);
        printf("\n");
    }
}
int main ()
{
    int n;
    scanf("%d",&n);
    int ara[n];
    for(int i = 0; i<n;i++){
        scanf("%d",&ara[i]);
    }
    selection(ara,n);
    print(ara,n);
}
