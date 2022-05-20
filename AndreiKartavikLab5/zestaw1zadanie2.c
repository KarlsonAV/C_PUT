#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


void create_matrix(double **A, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = (double)rand()/RAND_MAX * 1.5;
        }
    }
}

double convert_to_B(double x) {
    return (double) ((sin(x) * sin(x)) - 3) / sqrt(x + 1);
}

void print_matrix(double **A, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int n, m;
    
    srand(time(NULL));

    printf("Input n: ");
    scanf("%d", &n);
    printf("\nInput m: ");
    scanf("%d", &m);
    printf("\n");
     
    double **A = (double**) malloc (n * m * sizeof(double*));
    double **B = (double**) malloc (n * m * sizeof(double*));
    for (int i = 0; i < n; i++){
        A[i] = (double*) malloc (m * sizeof(double*));   
        B[i] = (double*) malloc (m * sizeof(double*));   
    }
	
    create_matrix(A, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] >= -1 && A[i][j] <= 1 && A[i][j] + 1 > 0) {
                B[i][j] = convert_to_B(A[i][j]);
            }
            else {
                B[i][j] = 3.31;   
            }
        }
    }

    print_matrix(B, n, m);
}
