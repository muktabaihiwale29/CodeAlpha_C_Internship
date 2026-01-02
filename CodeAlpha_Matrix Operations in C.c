#include <stdio.h>

// Function to input a matrix
void inputMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int a[10][10], int b[10][10], int r, int c) {
    int sum[10][10], i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Result of Matrix Addition:\n");
    displayMatrix(sum, r, c);
}

// Matrix Multiplication
void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int c2) {
    int mul[10][10], i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            mul[i][j] = 0;
            for (k = 0; k < c1; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Result of Matrix Multiplication:\n");
    displayMatrix(mul, r1, c2);
}

// Matrix Transpose
void transposeMatrix(int a[10][10], int r, int c) {
    int t[10][10], i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }

    printf("Transpose of Matrix:\n");
    displayMatrix(t, c, r);
}

int main() {
    int a[10][10], b[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of first matrix:\n");
    inputMatrix(a, r1, c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of second matrix:\n");
    inputMatrix(b, r2, c2);

    if (r1 == r2 && c1 == c2) {
        addMatrix(a, b, r1, c1);
    } else {
        printf("Matrix addition not possible.\n");
    }

    if (c1 == r2) {
        multiplyMatrix(a, b, r1, c1, c2);
    } else {
        printf("Matrix multiplication not possible.\n");
    }

    transposeMatrix(a, r1, c1);

    return 0;
}
