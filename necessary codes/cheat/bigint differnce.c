#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void subtractBigIntegers(char num1[], char num2[], char diff[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 > len2 ? len1 : len2;

    reverse(num1);
    reverse(num2);

    int borrow = 0;
    for (int i = 0; i < len; i++) {
        int digit1 = i < len1 ? num1[i] - '0' : 0;
        int digit2 = i < len2 ? num2[i] - '0' : 0;
        if (digit1 < digit2 + borrow) {
            diff[i] = digit1 + 10 - digit2 - borrow + '0';
            borrow = 1;
        } else {
            diff[i] = digit1 - digit2 - borrow + '0';
            borrow = 0;
        }
    }

    diff[len] = '\0';
    reverse(diff);
}

int main() {
    char num1[100], num2[100], diff[101];
    printf("Enter first big integer: ");
    scanf("%s", num1);
    printf("Enter second big integer: ");
    scanf("%s", num2);

    subtractBigIntegers(num1, num2, diff);
    printf("Difference: %s\n", diff);

    return 0;
}
