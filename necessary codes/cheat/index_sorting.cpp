#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform index-based sorting
void sortArrayByIndex(double arr[], int index[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[index[i]] > arr[index[j]]) {
                swap(&index[i], &index[j]);
            }
        }
    }
}

// Function to print the array elements based on the sorted index
void printArrayBySortedIndex(double arr[], int index[], int size) {
    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", arr[index[i]]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d",&n);
    double array[n];
    for(int i = 0 ; i < n;i++)
    {
        scanf("%lf",&array[i]);
    }

    int index[n];
    for (int i = 0; i < n; i++) {
        index[i] = i; // Initializing index array with values 0 to size-1
    }

    sortArrayByIndex(array, index, n);

    printArrayBySortedIndex(array, index, n);

    return 0;
}
