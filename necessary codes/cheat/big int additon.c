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

void addBigIntegers(char num1[], char num2[], char sum[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 > len2 ? len1 : len2;

    reverse(num1);
    reverse(num2);

    int carry = 0;
    for (int i = 0; i < len; i++) {
        int digit1 = i < len1 ? num1[i] - '0' : 0;
        int digit2 = i < len2 ? num2[i] - '0' : 0;
        int digitSum = digit1 + digit2 + carry;
        sum[i] = (digitSum % 10) + '0';
        carry = digitSum / 10;
    }

    if (carry > 0)
        sum[len++] = carry + '0';

    sum[len] = '\0';
    reverse(sum);
}

int main() {
    char num1[100], num2[100], sum[101];
    printf("Enter first big integer: ");
    scanf("%s", num1);
    printf("Enter second big integer: ");
    scanf("%s", num2);

    addBigIntegers(num1, num2, sum);
    printf("Sum: %s\n", sum);

    return 0;
}
