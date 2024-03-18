#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum number of digits in the result

void multiply(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // Create an array to store the result
    int res[MAX_SIZE] = {0};

    int i_n1 = 0;
    int i_n2 = 0;
    int carry = 0;

    // Multiply each digit of num1 with each digit of num2
    for (int i = len1 - 1; i >= 0; i--) {
        carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;

        for (int j = len2 - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + res[i_n1 + i_n2] + carry;

            carry = sum / 10;
            res[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }

        if (carry > 0)
            res[i_n1 + i_n2] += carry;

        i_n1++;
    }

    // Find the index where the result starts
    int resultIndex = MAX_SIZE - 1;
    while (resultIndex >= 0 && res[resultIndex] == 0)
        resultIndex--;

    // If resultIndex is negative, the multiplication is 0
    if (resultIndex == -1) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }

    // Convert the result array to characters
    int j = 0;
    for (int i = resultIndex; i >= 0; i--) {
        result[j++] = res[i] + '0';
    }
    result[j] = '\0';
}

int main() {
    char num1[MAX_SIZE];
    char num2[MAX_SIZE];
    char result[MAX_SIZE * 2]; // Maximum size of the result

    printf("Enter first number: ");
    scanf("%s", num1);

    printf("Enter second number: ");
    scanf("%s", num2);

    multiply(num1, num2, result);
    printf("Result of multiplication: %s\n", result);

    return 0;
}
