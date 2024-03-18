#include<stdio.h>
#include<limits.h>
int max_subarray(int ara[],int n)
{
        int max = ara[0];
        int sum = 0;
        for(int i = 0 ; i < n; i++){
            sum += ara[i];
            if(sum > max){
                max = sum;
            }
            if(sum < 0){
                sum = 0;
            }

        }
        return max;
}
 int main ()
 {
    int n;
    scanf("%d",&n);
    int ara[n];
    for(int i = 0 ; i < n;i++){
        scanf("%d",&ara[i]);
    }
    printf("maximum subarray sum = %d\n",max_subarray(ara,n));
 }
