#include <stdio.h>
#include <stdlib.h>


void create_R(double A[15][15], double B[15][15], int R[15][15], int n, int m) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                R[i][j] = 0;
            }
            else {
                R[i][j] = 1;
            }
        }
    }
}

void create_P(double A[15][15], double B[15][15], int P[15][15], int n, int m) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] <= B[i][j]) {
                P[i][j] = 0;
            }
            else {
                P[i][j] = 1;
            }
        }
    }
}


void print_matrix(int A[15][15], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int n, m;
    
    printf("Input n: ");
    scanf("%d", &n);
    printf("\nInput m: ");
    scanf("%d", &m);
    printf("\n");

    if (n <= 0 || n >= 15 || m <= 0 || m >= 15) {
        printf("Error occured\n");
        return 1;
    }

    double A[15][15], B[15][15];
    int P[15][15], R[15][15];

    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter element: ");
            scanf("%lf", &A[i][j]);
            printf("\n");
        }
    }

    printf("Enter elements for matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter element: ");
            scanf("%lf", &B[i][j]);
            printf("\n");
        }
    }

    create_R(A, B, R, n, m);
    create_P(A, B, P, n, m);
    printf("Matrix R:\n");
    print_matrix(R, n, m);
    printf("Matrix P:\n");
    print_matrix(P, n, m);
}