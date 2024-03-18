#include <stdio.h>S

#define ROWS 3
#define COLS 3

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort each column of the matrix
void sortColumns(int mat[ROWS][COLS]) {
    for (int i = 0; i < COLS; i++) {
        // Bubble sort for each column
        for (int j = 0; j < ROWS - 1; j++) {
            for (int k = 0; k < ROWS - j - 1; k++) {
                if (mat[k][i] > mat[k + 1][i]) {
                    // Swap elements if they are in the wrong order
                    swap(&mat[k][i], &mat[k + 1][i]);
                }
            }
        }
    }
}

// Function to display the matrix
void displayMatrix(int mat[ROWS][COLS]) {
    printf("Sorted Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {3, 2, 1},
        {6, 5, 4},
        {9, 8, 7}
    };

    printf("Original Matrix:\n");
    displayMatrix(matrix);

    sortColumns(matrix);

    displayMatrix(matrix);

    return 0;
}
