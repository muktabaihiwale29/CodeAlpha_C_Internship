#include <stdio.h>

int main() {
    float num1, num2, result;
    char op;

    // Input two numbers
    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    // Input operator
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);   // space before %c avoids input issues

    // Switch case for operation selection
    switch (op) {
        case '+':
            result = num1 + num2;
            printf("Result = %.2f", result);
            break;

        case '-':
            result = num1 - num2;
            printf("Result = %.2f", result);
            break;

        case '*':
            result = num1 * num2;
            printf("Result = %.2f", result);
            break;

        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result = %.2f", result);
            } else {
                printf("Error! Division by zero is not allowed.");
            }
            break;

        default:
            printf("Invalid operator!");
    }

    return 0;
}
