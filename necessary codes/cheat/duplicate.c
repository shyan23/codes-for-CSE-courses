#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int arr[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n\n");
    for(int i = 0; i < m;i++){
        for(int j = 0; j<n;j++){
            for(int k = i; k < m;k++){
                for(int l = 0; l <n;l++){
                    if(k == i && l<=j)continue;
                        if(arr[i][j] == arr[k][l]){
                            arr[k][l] = -1;
                        }       
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
